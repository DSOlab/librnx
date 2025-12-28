#include <stdexcept>
#include <cstdio>
#include "obstypes.hpp"

/** The function will check the type DorisObservationType instance, to see if
 *  frequency information is needed for this DorisObservationType. That is,
 *  it will return true if type is any of:
 *  * DorisObservationType::phase, or
 *  * DorisObservationType::pseudorange, or
 *  * DorisObservationType::power_level
 */
bool dso::dobstype_has_frequency(dso::DorisObservationType type) noexcept {
  switch (type) {
    case (DorisObservationType::phase):
    case (DorisObservationType::pseudorange):
    case (DorisObservationType::power_level):
      return true;
    case (DorisObservationType::frequency_offset):
    case (DorisObservationType::ground_pressure):
    case (DorisObservationType::ground_temperature):
    case (DorisObservationType::ground_humidity):
    default:
      return false;
  }
}

/** If the ObservationType is any of phase, pseudorange or power_level, then
 *  the freq must be either 1 or 2. Otherwise (i.e. if type is not in phase,
 *  pseudorange or power_level), the passed in frequency is ignored and set to
 *  0.
 *
 *  If the type is any of phase, pseudorange or power_level, and freq is not
 *  in range [1,2], then the constructor will throw an std::runtime_error.
 */
dso::DorisObservationCode::DorisObservationCode(dso::DorisObservationType type,
                                                int freq)
    : m_type(type), m_freq(freq) {
  if (dso::dobstype_has_frequency(m_type)) {
    if (m_freq < 1 || m_freq > 2) {
      throw std::runtime_error("[ERROR] Invalid DORIS frequency number");
    }
  } else {
    m_freq = 0;
  }
}

char *dso::DorisObservationCode::to_str(char *buffer) const noexcept {
  using DorisObsType = dso::SatelliteSystemObservationType<dso::SATELLITE_SYSTEM::DORIS>;
  std::sprintf(buffer, "%c%1d", DorisObsType::obst2char(m_type), (int)m_freq);
  return buffer;
}
