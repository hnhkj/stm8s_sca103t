//
// file: sca103t.h
//

#ifndef __SCA103T_H_
#define __SCA103T_H_

#define SCA103T_CMD_MEAS        0x00    // Measure mode
#define SCA103T_CMD_PWTR        0x08    // Read and write temperature data register
#define SCA103T_CMD_RDSR        0x0C    // Read status register
#define SCA103T_CMD_RLOAD       0x0D    // Reload NV data to memory output register
#define SCA103T_CMD_STX         0x0E    // Activate Self test for X-channel
#define SCA103T_CMD_STY         0x0F    // Activate Self test for Y-channel
#define SCA103T_RDAX            0x10    // Read X-channel acceleration through SPI
#define SCA103T_RDAY            0x11    // Read Y-channel acceleration through SPI

// spi driver function
void spi_nss_init(void);
void spi_nss_hi(void);
void spi_nss_low(void);
void spi_nss_rev(void);

// SCA103T function

/*
Read temperature data register(RWTR) reads the temperature data register during nomal
operation without effecting the operation. Temperature data register is updated every 150us. The
load operation is disabled whenever the CSB signal is low, hence CSB must stay high at least 150
us prior to the PWTR command in order to guarantee correct data. The data is transferred MSB first.
In normal operation, it does not matter what data is writted into temperature data register
during the PWTR command and hence writing all zeros is recommended.
*/
uint8_t SCA103T_ReadTemp(void);

/*
 * During normal operation, acceleration data register are reloaded every 150us.
 * The load operation is disabled whenever the CSB signal is low, hence CSB must
 * stay high at least 150us prior to he RADX command in order to guarantee correct
 * data. Data output is an 11-bit digital word that is out MSB first and LSB last.
 */
uint16_t SCA103T_ReadXchAcc(void);
uint16_t SCA103T_ReadYchAcc(void);

#endif