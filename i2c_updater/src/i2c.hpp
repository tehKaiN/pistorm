/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _I2C_HPP_
#define _I2C_HPP_

#include <string>
#include <vector>

class tI2c {
public:
	tI2c(const std::string &Port, bool isCombinedRw);

	bool write(uint8_t ubAddr, const std::vector<uint8_t> &vData);

	bool read(uint8_t ubAddr, uint8_t *pDest, uint32_t ulReadSize);

	bool writeRead(
		uint8_t ubAddr, const std::vector<uint8_t> &vData,
		uint8_t *pReadDest, uint32_t ulReadSize
	);

	template <typename t_tContainer>
	bool read(uint8_t ubAddr, t_tContainer &Cont) {
		return read(ubAddr, Cont.data(), Cont.size() * sizeof(Cont[0]));
	}

	template <typename t_tContainer>
	bool writeRead(
		uint8_t ubAddr, const std::vector<uint8_t> &vData, t_tContainer &Cont
	) {
		return writeRead(ubAddr, vData, Cont.data(), Cont.size() * sizeof(Cont[0]));
	}

private:
	int m_I2cHandle;
	bool m_isCombinedRw;
};

#endif // _I2C_HPP_
