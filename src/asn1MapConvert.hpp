/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Conversion functions for asn1DepthMap (header).
 */

#ifndef ASN1MAPCONVERT_HPP
#define ASN1MAPCONVERT_HPP

#include "asn1/Map.h"
#include "maps/grid/MLSMap.hpp"


// Conversion functions
void DepthMap_fromAsn1(::maps::grid::MLSMap< maps::grid::MLSConfig::BASE>& result, const asn1SccMap& asnVal);
void DepthMap_toAsn1(asn1SccMap& result, const ::maps::grid::MLSMap<maps::grid::MLSConfig::BASE>& baseObj);

#endif //ASN1DEPTHMAPCONVERT_HPP
