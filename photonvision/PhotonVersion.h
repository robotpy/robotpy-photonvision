/*
 * Copyright (C) Photon Vision.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <regex>

/*
 * This file should be generated, but isn't.
 * TODO: Remove on the next release
 * https://github.com/PhotonVision/photonvision/issues/770
 */

namespace photonlib {
  namespace PhotonVersion {
    const std::string versionString = "v2023.2.1";
    const std::string buildDate = "unknown";
    const bool isRelease = !(versionString.rfind("dev", 0) == 0);
  }

  bool VersionMatches(const std::string& other) {
    std::smatch match;
    std::regex versionPattern{"v[0-9]+.[0-9]+.[0-9]+"};
    // Check that both versions are in the right format
    if (std::regex_search(PhotonVersion::versionString, match, versionPattern) &&
        std::regex_search(other, match, versionPattern)) {
      // If they are, check string equality
      return (PhotonVersion::versionString == other);
    } else {
        return false;
    }
  }
}
