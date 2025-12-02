#include "doris_rinex.hpp"
#include <cstdio>
#include <datetime/core/datetime_io_core.hpp>
#include "datetime/datetime_write.hpp"
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

using namespace dso;

int main(int argc, char *argv[]) {
  if (argc!=2) {
    fprintf(stderr, "Error. Usage %s [DORIS RINEX]\n", argv[0]);
    return 1;
  }

  DorisObsRinex rnx (argv[1]);

  char buf[64];
  int epochs = 0;
  for (auto it = rnx.begin(); it != rnx.end(); ++it) {
    /* each it instance is of type DataBlock and has a 
     * RinexDataRecordHeader mheader; and
     * std::vector<BeaconObservations> mbeacon_obs;
     */
    const auto tai = it->mheader.corrected_epoch();
    dso::to_char<dso::YMDFormat::YYYYMMDD, dso::HMSFormat::HHMMSSF>(tai, buf);
    const int num_beacons = it->mheader.m_num_stations;
    printf("New epoch at %s, with %d beacons\n", buf, num_beacons);
    ++epochs;
  }

  assert(epochs > 0);
  printf("Num of epochs read: %d\n", epochs);

  return 0;
}
