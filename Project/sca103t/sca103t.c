//
// file: sca103t.c
//

#include "stm8s.h"
#include "sca103t.h"

#define SPI_NSS_PORT    (GPIOA)
#define SPI_NSS_PIN     (GPIO_PIN_3)

void spi_nss_init(void)
{
  GPIO_Init(SPI_NSS_PORT, (GPIO_Pin_TypeDef)(SPI_NSS_PIN),GPIO_MODE_OUT_PP_HIGH_FAST);
  spi_nss_hi();
}

void spi_nss_hi(void)
{
  GPIO_WriteHigh(SPI_NSS_PORT, SPI_NSS_PIN);
}

void spi_nss_low(void)
{
  GPIO_WriteLow(SPI_NSS_PORT, SPI_NSS_PIN);
}

void spi_nss_rev(void)
{
  GPIO_WriteReverse(SPI_NSS_PORT, SPI_NSS_PIN);
}


/**
  * @brief  Write a byte on the SD.
  * @param  Data: byte to send.
  * @retval None
  */
uint8_t Spi_WriteByte(uint8_t Data)
{
  /*!< Wait until the transmit buffer is empty */
//  while (SPI_GetFlagStatus(SPI_FLAG_TXE) == RESET)
//  {}

  /*!< Send the byte */
  SPI_SendData(Data);

  /*!< Wait to receive a byte*/
  while (SPI_GetFlagStatus(SPI_FLAG_RXNE) == RESET)
  {}

  /*!< Return the byte read from the SPI bus */
  return SPI_ReceiveData();
}

/**
  * @brief  Read a byte from the SD.
  * @param  None
  * @retval The received byte.
  */
uint8_t Spi_ReadByte(void)
{
  uint8_t Data = 0;

  /*!< Wait until the transmit buffer is empty */
//  while (SPI_GetFlagStatus(SPI_FLAG_TXE) == RESET)
//  {}
  /*!< Send the byte */
  SPI_SendData(0);

  /*!< Wait until a data is received */
  while (SPI_GetFlagStatus(SPI_FLAG_RXNE) == RESET)
  {}
  /*!< Get the received data */
  Data = SPI_ReceiveData();

  /*!< Return the shifted data */
  return Data;
}

// SCA103T funciton

uint8_t SCA103T_ReadTemp(void)
{
  uint8_t dat=0;
  spi_nss_low();

  Spi_WriteByte(SCA103T_CMD_PWTR);
  dat =  Spi_ReadByte();
  spi_nss_hi();
  return dat;
}

uint16_t SCA103T_ReadXchAcc(void)
{
  uint16_t dat=0;
  uint8_t dath=0,datl=0;
  spi_nss_low();

  Spi_WriteByte(SCA103T_RDAX);
  dath = Spi_ReadByte();
  datl = Spi_ReadByte();
  spi_nss_hi();
  dat = dath*128+datl;
  dat = dat >> 5;
  return dat; 
}

uint16_t SCA103T_ReadYchAcc(void)
{
  uint16_t dat=0;
  uint8_t dath=0,datl=0;
  spi_nss_low();

  Spi_WriteByte(SCA103T_RDAY);
  dath = Spi_ReadByte();
  datl = Spi_ReadByte();
  spi_nss_hi();
  dat = dath*128+datl;
  dat = dat >> 5;
  return dat; 
}