//
//  version.h
//  m17ref
//
//  Created by Jean-Luc Deltombe (LX3JL) on 05/01/2018.
//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.
//  Copyright © 2022 Thomas A. Early N7TAE.
//
// ----------------------------------------------------------------------------
//    This file is part of m17ref.
//
//    m17ref is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    m17ref is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    with this software.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include "version.h"

CVersion g_Version(0, 8, 3);	// the global object!

CVersion::CVersion(uint8_t maj, uint8_t min, uint8_t rev) : version(0x10000*maj + 0x100*min + rev) {}

uint8_t CVersion::GetMajor(void) const
{
	return uint8_t(version / 0x10000);
}

uint8_t CVersion::GetMinor(void) const
{
	return uint8_t(version / 0x100 % 0x100);
}

uint8_t CVersion::GetRevision(void) const
{
	return uint8_t(version % 100);
}

int CVersion::GetVersion(void)  const
{
	return version;
}

bool CVersion::operator ==(const CVersion &v) const
{
	return v.version == version;
};

bool CVersion::operator !=(const CVersion &v) const
{
	return v.version != version;
};

bool CVersion::operator >=(const CVersion &v) const
{
	return v.version >= version;
}

bool CVersion::operator <=(const CVersion &v) const
{
	return v.version <= version;
}
bool CVersion::operator >(const CVersion &v) const
{
	return v.version  > version;
}

bool CVersion::operator <(const CVersion &v) const
{
	return v.version  < version;
}

// output
std::ostream &operator <<(std::ostream &os, const CVersion &v)
{
	os << v.GetMajor() << '.' << v.GetMinor() << '.' << v.GetRevision();
	return os;
};
