#pragma once

// RFM69 Register definitions (основні регістри)
#define RFM69_REG_FIFO          0x00
#define RFM69_REG_OPMODE        0x01
#define RFM69_REG_DATAMODUL     0x02
#define RFM69_REG_BITRATEMSB    0x03
#define RFM69_REG_BITRATELSB    0x04
#define RFM69_REG_FDEVMSB       0x05
#define RFM69_REG_FDEVLSB       0x06
#define RFM69_REG_FRFMSB        0x07
#define RFM69_REG_FRFMID        0x08
#define RFM69_REG_FRFLSB        0x09
#define RFM69_REG_OSC1          0x0A
#define RFM69_REG_AFCCTRL       0x0B
#define RFM69_REG_LISTEN1       0x0D
#define RFM69_REG_VERSION       0x10
#define RFM69_REG_PALEVEL       0x11
#define RFM69_REG_OCP           0x13
#define RFM69_REG_LNA           0x18
#define RFM69_REG_RXBW          0x19
#define RFM69_REG_AFCBW         0x1A
#define RFM69_REG_RSSIVALUE     0x24
#define RFM69_REG_DIOMAPPING1   0x25
#define RFM69_REG_DIOMAPPING2   0x26
#define RFM69_REG_IRQFLAGS1     0x27
#define RFM69_REG_IRQFLAGS2     0x28
#define RFM69_REG_RSSITHRESH    0x29
#define RFM69_REG_PREAMBLEMSB   0x2C
#define RFM69_REG_PREAMBLELSB   0x2D
#define RFM69_REG_SYNCCONFIG    0x2E
#define RFM69_REG_SYNCVALUE1    0x2F
#define RFM69_REG_SYNCVALUE2    0x30
#define RFM69_REG_PACKETCONFIG1 0x37
#define RFM69_REG_PAYLOADLENGTH 0x38
#define RFM69_REG_NODEADRS      0x39
#define RFM69_REG_BROADCASTADRS 0x3A
#define RFM69_REG_FIFOTHRESH    0x3C
#define RFM69_REG_PACKETCONFIG2 0x3D
#define RFM69_REG_AESKEY1       0x3E
#define RFM69_REG_TESTPA1       0x5A
#define RFM69_REG_TESTPA2       0x5C
#define RFM69_REG_TESTDAGC      0x6F

// Operation modes
#define RFM69_OPMODE_SEQUENCER_ON        0x00
#define RFM69_OPMODE_SEQUENCER_OFF       0x80
#define RFM69_OPMODE_LISTEN_ON           0x40
#define RFM69_OPMODE_LISTEN_OFF          0x00
#define RFM69_OPMODE_SLEEP               0x00
#define RFM69_OPMODE_STANDBY             0x04
#define RFM69_OPMODE_SYNTHESIZER         0x08
#define RFM69_OPMODE_TRANSMITTER         0x0C
#define RFM69_OPMODE_RECEIVER            0x10

// Data modulation
#define RFM69_DATAMODUL_DATAMODE_PACKET            0x00
#define RFM69_DATAMODUL_MODULATIONTYPE_FSK         0x00
#define RFM69_DATAMODUL_MODULATIONSHAPING_00       0x00

// Power amplifier level
#define RFM69_PALEVEL_PA0_ON     0x80
#define RFM69_PALEVEL_PA0_OFF    0x00
#define RFM69_PALEVEL_PA1_ON     0x40
#define RFM69_PALEVEL_PA1_OFF    0x00
#define RFM69_PALEVEL_PA2_ON     0x20
#define RFM69_PALEVEL_PA2_OFF    0x00

// IRQ flags
#define RFM69_IRQFLAGS1_MODEREADY            0x80
#define RFM69_IRQFLAGS2_FIFOOVERRUN          0x10
#define RFM69_IRQFLAGS2_PACKETSENT           0x08
#define RFM69_IRQFLAGS2_PAYLOADREADY         0x04
#define RFM69_IRQFLAGS2_FIFOLEVEL            0x20

// DIO mapping
#define RFM69_DIOMAPPING1_DIO0_00            0x00
#define RFM69_DIOMAPPING1_DIO0_01            0x40
#define RFM69_DIOMAPPING2_CLKOUT_OFF         0x07

// Sync configuration  
#define RFM69_SYNC_ON                0x80
#define RFM69_SYNC_FIFOFILL_AUTO     0x00
#define RFM69_SYNC_SIZE_2            0x08
#define RFM69_SYNC_TOL_0             0x00

// Packet configuration
#define RFM69_PACKET1_FORMAT_VARIABLE    0x80
#define RFM69_PACKET1_DCFREE_OFF         0x00
#define RFM69_PACKET1_DCFREE_WHITENING   0x40
#define RFM69_PACKET1_CRC_ON             0x10
#define RFM69_PACKET1_CRCAUTOCLEAR_ON    0x00
#define RFM69_PACKET1_ADRSFILTERING_NODEBROADCAST  0x04

#define RFM69_PACKET2_RXRESTARTDELAY_2BITS       0x10
#define RFM69_PACKET2_AUTORXRESTART_OFF          0x00
#define RFM69_PACKET2_AES_ON                     0x01
#define RFM69_PACKET2_AES_OFF                    0x00

// Other constants
#define RFM69_SYNCVALUE1         0x2D
#define RFM69_RSSITHRESH_VALUE   0xE4
#define RFM69_PREAMBLESIZE_MSB_VALUE         0x00
#define RFM69_PREAMBLESIZE_LSB_VALUE         0x03
#define RFM69_FIFOTHRESH_TXSTART_FIFONOTEMPTY    0x80
#define RFM69_LNA_ZIN_200                0x80
#define RFM69_LNA_CURRENTGAIN            0x08
#define RFM69_DAGC_IMPROVED_LOWBETA0     0x30
#define RFM69_OCP_OFF                0x0F
#define RFM69_OCP_ON                 0x1A
#define RFM69_OCP_TRIM_95            0x0A

// Read/Write masks
#define RFM69_READ_REGISTER		0x7F
#define RFM69_WRITE_REGISTER	0x80