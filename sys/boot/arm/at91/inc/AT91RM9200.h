begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// ----------------------------------------------------------------------------
end_comment

begin_comment
comment|//          ATMEL Microcontroller Software Support  -  ROUSSET  -
end_comment

begin_comment
comment|// ----------------------------------------------------------------------------
end_comment

begin_comment
comment|//  The software is delivered "AS IS" without warranty or condition of any
end_comment

begin_comment
comment|//  kind, either express, implied or statutory. This includes without
end_comment

begin_comment
comment|//  limitation any warranty or condition with respect to merchantability or
end_comment

begin_comment
comment|//  fitness for any particular purpose, or against the infringements of
end_comment

begin_comment
comment|//  intellectual property rights of others.
end_comment

begin_comment
comment|// ----------------------------------------------------------------------------
end_comment

begin_comment
comment|// $FreeBSD$
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// File Name           : AT91RM9200.h
end_comment

begin_comment
comment|// Object              : AT91RM9200 definitions
end_comment

begin_comment
comment|// Generated           : AT91 SW Application Group  07/04/2003 (11:05:04)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CVS Reference       : /AT91RM9200.pl/1.16/Fri Feb 07 09:29:50 2003//
end_comment

begin_comment
comment|// CVS Reference       : /SYS_AT91RM9200.pl/1.2/Fri Jan 17 11:44:36 2003//
end_comment

begin_comment
comment|// CVS Reference       : /MC_1760A.pl/1.1/Fri Aug 23 13:38:22 2002//
end_comment

begin_comment
comment|// CVS Reference       : /AIC_1796B.pl/1.1.1.1/Fri Jun 28 08:36:46 2002//
end_comment

begin_comment
comment|// CVS Reference       : /PMC_2636A.pl/1.1.1.1/Fri Jun 28 08:36:48 2002//
end_comment

begin_comment
comment|// CVS Reference       : /ST_1763B.pl/1.1/Fri Aug 23 13:41:42 2002//
end_comment

begin_comment
comment|// CVS Reference       : /RTC_1245D.pl/1.2/Fri Jan 31 11:19:06 2003//
end_comment

begin_comment
comment|// CVS Reference       : /PIO_1725D.pl/1.1.1.1/Fri Jun 28 08:36:46 2002//
end_comment

begin_comment
comment|// CVS Reference       : /DBGU_1754A.pl/1.4/Fri Jan 31 11:18:24 2003//
end_comment

begin_comment
comment|// CVS Reference       : /UDP_1765B.pl/1.3/Fri Aug 02 13:45:38 2002//
end_comment

begin_comment
comment|// CVS Reference       : /MCI_1764A.pl/1.2/Thu Nov 14 16:48:24 2002//
end_comment

begin_comment
comment|// CVS Reference       : /US_1739C.pl/1.2/Fri Jul 12 06:49:24 2002//
end_comment

begin_comment
comment|// CVS Reference       : /SPI_AT91RMxxxx.pl/1.3/Tue Nov 26 09:20:28 2002//
end_comment

begin_comment
comment|// CVS Reference       : /SSC_1762A.pl/1.2/Fri Nov 08 12:26:38 2002//
end_comment

begin_comment
comment|// CVS Reference       : /TC_1753B.pl/1.2/Fri Jan 31 11:19:54 2003//
end_comment

begin_comment
comment|// CVS Reference       : /TWI_1761B.pl/1.4/Fri Feb 07 09:30:06 2003//
end_comment

begin_comment
comment|// CVS Reference       : /PDC_1734B.pl/1.2/Thu Nov 21 15:38:22 2002//
end_comment

begin_comment
comment|// CVS Reference       : /UHP_xxxxA.pl/1.1/Mon Jul 22 11:21:58 2002//
end_comment

begin_comment
comment|// CVS Reference       : /EMAC_1794A.pl/1.4/Fri Jan 17 11:11:54 2003//
end_comment

begin_comment
comment|// CVS Reference       : /EBI_1759B.pl/1.10/Fri Jan 17 11:44:28 2003//
end_comment

begin_comment
comment|// CVS Reference       : /SMC_1783A.pl/1.3/Thu Oct 31 13:38:16 2002//
end_comment

begin_comment
comment|// CVS Reference       : /SDRC_1758B.pl/1.2/Thu Oct 03 12:04:40 2002//
end_comment

begin_comment
comment|// CVS Reference       : /BFC_1757B.pl/1.3/Thu Oct 31 13:38:00 2002//
end_comment

begin_comment
comment|// ----------------------------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91RM9200_H
end_ifndef

begin_define
define|#
directive|define
name|AT91RM9200_H
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|int
name|AT91_REG
typedef|;
end_typedef

begin_comment
comment|// Hardware register definition
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR System Peripherals
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_SYS
block|{
name|AT91_REG
name|AIC_SMR
index|[
literal|32
index|]
decl_stmt|;
comment|// Source Mode Register
name|AT91_REG
name|AIC_SVR
index|[
literal|32
index|]
decl_stmt|;
comment|// Source Vector Register
name|AT91_REG
name|AIC_IVR
decl_stmt|;
comment|// IRQ Vector Register
name|AT91_REG
name|AIC_FVR
decl_stmt|;
comment|// FIQ Vector Register
name|AT91_REG
name|AIC_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|AIC_IPR
decl_stmt|;
comment|// Interrupt Pending Register
name|AT91_REG
name|AIC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|AIC_CISR
decl_stmt|;
comment|// Core Interrupt Status Register
name|AT91_REG
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|AIC_IECR
decl_stmt|;
comment|// Interrupt Enable Command Register
name|AT91_REG
name|AIC_IDCR
decl_stmt|;
comment|// Interrupt Disable Command Register
name|AT91_REG
name|AIC_ICCR
decl_stmt|;
comment|// Interrupt Clear Command Register
name|AT91_REG
name|AIC_ISCR
decl_stmt|;
comment|// Interrupt Set Command Register
name|AT91_REG
name|AIC_EOICR
decl_stmt|;
comment|// End of Interrupt Command Register
name|AT91_REG
name|AIC_SPU
decl_stmt|;
comment|// Spurious Vector Register
name|AT91_REG
name|AIC_DCR
decl_stmt|;
comment|// Debug Control Register (Protect)
name|AT91_REG
name|Reserved1
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|AIC_FFER
decl_stmt|;
comment|// Fast Forcing Enable Register
name|AT91_REG
name|AIC_FFDR
decl_stmt|;
comment|// Fast Forcing Disable Register
name|AT91_REG
name|AIC_FFSR
decl_stmt|;
comment|// Fast Forcing Status Register
name|AT91_REG
name|Reserved2
index|[
literal|45
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|DBGU_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|DBGU_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|DBGU_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|DBGU_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|DBGU_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|DBGU_CSR
decl_stmt|;
comment|// Channel Status Register
name|AT91_REG
name|DBGU_RHR
decl_stmt|;
comment|// Receiver Holding Register
name|AT91_REG
name|DBGU_THR
decl_stmt|;
comment|// Transmitter Holding Register
name|AT91_REG
name|DBGU_BRGR
decl_stmt|;
comment|// Baud Rate Generator Register
name|AT91_REG
name|Reserved3
index|[
literal|7
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|DBGU_C1R
decl_stmt|;
comment|// Chip ID1 Register
name|AT91_REG
name|DBGU_C2R
decl_stmt|;
comment|// Chip ID2 Register
name|AT91_REG
name|DBGU_FNTR
decl_stmt|;
comment|// Force NTRST Register
name|AT91_REG
name|Reserved4
index|[
literal|45
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|DBGU_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|DBGU_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|DBGU_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|DBGU_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|DBGU_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|DBGU_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|DBGU_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|DBGU_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|DBGU_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|DBGU_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
name|AT91_REG
name|Reserved5
index|[
literal|54
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_PER
decl_stmt|;
comment|// PIO Enable Register
name|AT91_REG
name|PIOA_PDR
decl_stmt|;
comment|// PIO Disable Register
name|AT91_REG
name|PIOA_PSR
decl_stmt|;
comment|// PIO Status Register
name|AT91_REG
name|Reserved6
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_OER
decl_stmt|;
comment|// Output Enable Register
name|AT91_REG
name|PIOA_ODR
decl_stmt|;
comment|// Output Disable Registerr
name|AT91_REG
name|PIOA_OSR
decl_stmt|;
comment|// Output Status Register
name|AT91_REG
name|Reserved7
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_IFER
decl_stmt|;
comment|// Input Filter Enable Register
name|AT91_REG
name|PIOA_IFDR
decl_stmt|;
comment|// Input Filter Disable Register
name|AT91_REG
name|PIOA_IFSR
decl_stmt|;
comment|// Input Filter Status Register
name|AT91_REG
name|Reserved8
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_SODR
decl_stmt|;
comment|// Set Output Data Register
name|AT91_REG
name|PIOA_CODR
decl_stmt|;
comment|// Clear Output Data Register
name|AT91_REG
name|PIOA_ODSR
decl_stmt|;
comment|// Output Data Status Register
name|AT91_REG
name|PIOA_PDSR
decl_stmt|;
comment|// Pin Data Status Register
name|AT91_REG
name|PIOA_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PIOA_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PIOA_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|PIOA_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|PIOA_MDER
decl_stmt|;
comment|// Multi-driver Enable Register
name|AT91_REG
name|PIOA_MDDR
decl_stmt|;
comment|// Multi-driver Disable Register
name|AT91_REG
name|PIOA_MDSR
decl_stmt|;
comment|// Multi-driver Status Register
name|AT91_REG
name|Reserved9
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_PPUDR
decl_stmt|;
comment|// Pull-up Disable Register
name|AT91_REG
name|PIOA_PPUER
decl_stmt|;
comment|// Pull-up Enable Register
name|AT91_REG
name|PIOA_PPUSR
decl_stmt|;
comment|// Pad Pull-up Status Register
name|AT91_REG
name|Reserved10
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_ASR
decl_stmt|;
comment|// Select A Register
name|AT91_REG
name|PIOA_BSR
decl_stmt|;
comment|// Select B Register
name|AT91_REG
name|PIOA_ABSR
decl_stmt|;
comment|// AB Select Status Register
name|AT91_REG
name|Reserved11
index|[
literal|9
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOA_OWER
decl_stmt|;
comment|// Output Write Enable Register
name|AT91_REG
name|PIOA_OWDR
decl_stmt|;
comment|// Output Write Disable Register
name|AT91_REG
name|PIOA_OWSR
decl_stmt|;
comment|// Output Write Status Register
name|AT91_REG
name|Reserved12
index|[
literal|85
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_PER
decl_stmt|;
comment|// PIO Enable Register
name|AT91_REG
name|PIOB_PDR
decl_stmt|;
comment|// PIO Disable Register
name|AT91_REG
name|PIOB_PSR
decl_stmt|;
comment|// PIO Status Register
name|AT91_REG
name|Reserved13
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_OER
decl_stmt|;
comment|// Output Enable Register
name|AT91_REG
name|PIOB_ODR
decl_stmt|;
comment|// Output Disable Registerr
name|AT91_REG
name|PIOB_OSR
decl_stmt|;
comment|// Output Status Register
name|AT91_REG
name|Reserved14
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_IFER
decl_stmt|;
comment|// Input Filter Enable Register
name|AT91_REG
name|PIOB_IFDR
decl_stmt|;
comment|// Input Filter Disable Register
name|AT91_REG
name|PIOB_IFSR
decl_stmt|;
comment|// Input Filter Status Register
name|AT91_REG
name|Reserved15
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_SODR
decl_stmt|;
comment|// Set Output Data Register
name|AT91_REG
name|PIOB_CODR
decl_stmt|;
comment|// Clear Output Data Register
name|AT91_REG
name|PIOB_ODSR
decl_stmt|;
comment|// Output Data Status Register
name|AT91_REG
name|PIOB_PDSR
decl_stmt|;
comment|// Pin Data Status Register
name|AT91_REG
name|PIOB_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PIOB_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PIOB_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|PIOB_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|PIOB_MDER
decl_stmt|;
comment|// Multi-driver Enable Register
name|AT91_REG
name|PIOB_MDDR
decl_stmt|;
comment|// Multi-driver Disable Register
name|AT91_REG
name|PIOB_MDSR
decl_stmt|;
comment|// Multi-driver Status Register
name|AT91_REG
name|Reserved16
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_PPUDR
decl_stmt|;
comment|// Pull-up Disable Register
name|AT91_REG
name|PIOB_PPUER
decl_stmt|;
comment|// Pull-up Enable Register
name|AT91_REG
name|PIOB_PPUSR
decl_stmt|;
comment|// Pad Pull-up Status Register
name|AT91_REG
name|Reserved17
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_ASR
decl_stmt|;
comment|// Select A Register
name|AT91_REG
name|PIOB_BSR
decl_stmt|;
comment|// Select B Register
name|AT91_REG
name|PIOB_ABSR
decl_stmt|;
comment|// AB Select Status Register
name|AT91_REG
name|Reserved18
index|[
literal|9
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOB_OWER
decl_stmt|;
comment|// Output Write Enable Register
name|AT91_REG
name|PIOB_OWDR
decl_stmt|;
comment|// Output Write Disable Register
name|AT91_REG
name|PIOB_OWSR
decl_stmt|;
comment|// Output Write Status Register
name|AT91_REG
name|Reserved19
index|[
literal|85
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_PER
decl_stmt|;
comment|// PIO Enable Register
name|AT91_REG
name|PIOC_PDR
decl_stmt|;
comment|// PIO Disable Register
name|AT91_REG
name|PIOC_PSR
decl_stmt|;
comment|// PIO Status Register
name|AT91_REG
name|Reserved20
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_OER
decl_stmt|;
comment|// Output Enable Register
name|AT91_REG
name|PIOC_ODR
decl_stmt|;
comment|// Output Disable Registerr
name|AT91_REG
name|PIOC_OSR
decl_stmt|;
comment|// Output Status Register
name|AT91_REG
name|Reserved21
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_IFER
decl_stmt|;
comment|// Input Filter Enable Register
name|AT91_REG
name|PIOC_IFDR
decl_stmt|;
comment|// Input Filter Disable Register
name|AT91_REG
name|PIOC_IFSR
decl_stmt|;
comment|// Input Filter Status Register
name|AT91_REG
name|Reserved22
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_SODR
decl_stmt|;
comment|// Set Output Data Register
name|AT91_REG
name|PIOC_CODR
decl_stmt|;
comment|// Clear Output Data Register
name|AT91_REG
name|PIOC_ODSR
decl_stmt|;
comment|// Output Data Status Register
name|AT91_REG
name|PIOC_PDSR
decl_stmt|;
comment|// Pin Data Status Register
name|AT91_REG
name|PIOC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PIOC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PIOC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|PIOC_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|PIOC_MDER
decl_stmt|;
comment|// Multi-driver Enable Register
name|AT91_REG
name|PIOC_MDDR
decl_stmt|;
comment|// Multi-driver Disable Register
name|AT91_REG
name|PIOC_MDSR
decl_stmt|;
comment|// Multi-driver Status Register
name|AT91_REG
name|Reserved23
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_PPUDR
decl_stmt|;
comment|// Pull-up Disable Register
name|AT91_REG
name|PIOC_PPUER
decl_stmt|;
comment|// Pull-up Enable Register
name|AT91_REG
name|PIOC_PPUSR
decl_stmt|;
comment|// Pad Pull-up Status Register
name|AT91_REG
name|Reserved24
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_ASR
decl_stmt|;
comment|// Select A Register
name|AT91_REG
name|PIOC_BSR
decl_stmt|;
comment|// Select B Register
name|AT91_REG
name|PIOC_ABSR
decl_stmt|;
comment|// AB Select Status Register
name|AT91_REG
name|Reserved25
index|[
literal|9
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOC_OWER
decl_stmt|;
comment|// Output Write Enable Register
name|AT91_REG
name|PIOC_OWDR
decl_stmt|;
comment|// Output Write Disable Register
name|AT91_REG
name|PIOC_OWSR
decl_stmt|;
comment|// Output Write Status Register
name|AT91_REG
name|Reserved26
index|[
literal|85
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_PER
decl_stmt|;
comment|// PIO Enable Register
name|AT91_REG
name|PIOD_PDR
decl_stmt|;
comment|// PIO Disable Register
name|AT91_REG
name|PIOD_PSR
decl_stmt|;
comment|// PIO Status Register
name|AT91_REG
name|Reserved27
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_OER
decl_stmt|;
comment|// Output Enable Register
name|AT91_REG
name|PIOD_ODR
decl_stmt|;
comment|// Output Disable Registerr
name|AT91_REG
name|PIOD_OSR
decl_stmt|;
comment|// Output Status Register
name|AT91_REG
name|Reserved28
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_IFER
decl_stmt|;
comment|// Input Filter Enable Register
name|AT91_REG
name|PIOD_IFDR
decl_stmt|;
comment|// Input Filter Disable Register
name|AT91_REG
name|PIOD_IFSR
decl_stmt|;
comment|// Input Filter Status Register
name|AT91_REG
name|Reserved29
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_SODR
decl_stmt|;
comment|// Set Output Data Register
name|AT91_REG
name|PIOD_CODR
decl_stmt|;
comment|// Clear Output Data Register
name|AT91_REG
name|PIOD_ODSR
decl_stmt|;
comment|// Output Data Status Register
name|AT91_REG
name|PIOD_PDSR
decl_stmt|;
comment|// Pin Data Status Register
name|AT91_REG
name|PIOD_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PIOD_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PIOD_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|PIOD_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|PIOD_MDER
decl_stmt|;
comment|// Multi-driver Enable Register
name|AT91_REG
name|PIOD_MDDR
decl_stmt|;
comment|// Multi-driver Disable Register
name|AT91_REG
name|PIOD_MDSR
decl_stmt|;
comment|// Multi-driver Status Register
name|AT91_REG
name|Reserved30
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_PPUDR
decl_stmt|;
comment|// Pull-up Disable Register
name|AT91_REG
name|PIOD_PPUER
decl_stmt|;
comment|// Pull-up Enable Register
name|AT91_REG
name|PIOD_PPUSR
decl_stmt|;
comment|// Pad Pull-up Status Register
name|AT91_REG
name|Reserved31
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_ASR
decl_stmt|;
comment|// Select A Register
name|AT91_REG
name|PIOD_BSR
decl_stmt|;
comment|// Select B Register
name|AT91_REG
name|PIOD_ABSR
decl_stmt|;
comment|// AB Select Status Register
name|AT91_REG
name|Reserved32
index|[
literal|9
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIOD_OWER
decl_stmt|;
comment|// Output Write Enable Register
name|AT91_REG
name|PIOD_OWDR
decl_stmt|;
comment|// Output Write Disable Register
name|AT91_REG
name|PIOD_OWSR
decl_stmt|;
comment|// Output Write Status Register
name|AT91_REG
name|Reserved33
index|[
literal|85
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_SCER
decl_stmt|;
comment|// System Clock Enable Register
name|AT91_REG
name|PMC_SCDR
decl_stmt|;
comment|// System Clock Disable Register
name|AT91_REG
name|PMC_SCSR
decl_stmt|;
comment|// System Clock Status Register
name|AT91_REG
name|Reserved34
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_PCER
decl_stmt|;
comment|// Peripheral Clock Enable Register
name|AT91_REG
name|PMC_PCDR
decl_stmt|;
comment|// Peripheral Clock Disable Register
name|AT91_REG
name|PMC_PCSR
decl_stmt|;
comment|// Peripheral Clock Status Register
name|AT91_REG
name|Reserved35
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|CKGR_MOR
decl_stmt|;
comment|// Main Oscillator Register
name|AT91_REG
name|CKGR_MCFR
decl_stmt|;
comment|// Main Clock  Frequency Register
name|AT91_REG
name|CKGR_PLLAR
decl_stmt|;
comment|// PLL A Register
name|AT91_REG
name|CKGR_PLLBR
decl_stmt|;
comment|// PLL B Register
name|AT91_REG
name|PMC_MCKR
decl_stmt|;
comment|// Master Clock Register
name|AT91_REG
name|Reserved36
index|[
literal|3
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_PCKR
index|[
literal|8
index|]
decl_stmt|;
comment|// Programmable Clock Register
name|AT91_REG
name|PMC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PMC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PMC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|PMC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|Reserved37
index|[
literal|36
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|ST_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|ST_PIMR
decl_stmt|;
comment|// Period Interval Mode Register
name|AT91_REG
name|ST_WDMR
decl_stmt|;
comment|// Watchdog Mode Register
name|AT91_REG
name|ST_RTMR
decl_stmt|;
comment|// Real-time Mode Register
name|AT91_REG
name|ST_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|ST_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|ST_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|ST_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|ST_RTAR
decl_stmt|;
comment|// Real-time Alarm Register
name|AT91_REG
name|ST_CRTR
decl_stmt|;
comment|// Current Real-time Register
name|AT91_REG
name|Reserved38
index|[
literal|54
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|RTC_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|RTC_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|RTC_TIMR
decl_stmt|;
comment|// Time Register
name|AT91_REG
name|RTC_CALR
decl_stmt|;
comment|// Calendar Register
name|AT91_REG
name|RTC_TIMALR
decl_stmt|;
comment|// Time Alarm Register
name|AT91_REG
name|RTC_CALALR
decl_stmt|;
comment|// Calendar Alarm Register
name|AT91_REG
name|RTC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|RTC_SCCR
decl_stmt|;
comment|// Status Clear Command Register
name|AT91_REG
name|RTC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|RTC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|RTC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|RTC_VER
decl_stmt|;
comment|// Valid Entry Register
name|AT91_REG
name|Reserved39
index|[
literal|52
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MC_RCR
decl_stmt|;
comment|// MC Remap Control Register
name|AT91_REG
name|MC_ASR
decl_stmt|;
comment|// MC Abort Status Register
name|AT91_REG
name|MC_AASR
decl_stmt|;
comment|// MC Abort Address Status Register
name|AT91_REG
name|Reserved40
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MC_PUIA
index|[
literal|16
index|]
decl_stmt|;
comment|// MC Protection Unit Area
name|AT91_REG
name|MC_PUP
decl_stmt|;
comment|// MC Protection Unit Peripherals
name|AT91_REG
name|MC_PUER
decl_stmt|;
comment|// MC Protection Unit Enable Register
name|AT91_REG
name|Reserved41
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EBI_CSA
decl_stmt|;
comment|// Chip Select Assignment Register
name|AT91_REG
name|EBI_CFGR
decl_stmt|;
comment|// Configuration Register
name|AT91_REG
name|Reserved42
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EBI_SMC2_CSR
index|[
literal|8
index|]
decl_stmt|;
comment|// SMC2 Chip Select Register
name|AT91_REG
name|EBI_SDRC_MR
decl_stmt|;
comment|// SDRAM Controller Mode Register
name|AT91_REG
name|EBI_SDRC_TR
decl_stmt|;
comment|// SDRAM Controller Refresh Timer Register
name|AT91_REG
name|EBI_SDRC_CR
decl_stmt|;
comment|// SDRAM Controller Configuration Register
name|AT91_REG
name|EBI_SDRC_SRR
decl_stmt|;
comment|// SDRAM Controller Self Refresh Register
name|AT91_REG
name|EBI_SDRC_LPR
decl_stmt|;
comment|// SDRAM Controller Low Power Register
name|AT91_REG
name|EBI_SDRC_IER
decl_stmt|;
comment|// SDRAM Controller Interrupt Enable Register
name|AT91_REG
name|EBI_SDRC_IDR
decl_stmt|;
comment|// SDRAM Controller Interrupt Disable Register
name|AT91_REG
name|EBI_SDRC_IMR
decl_stmt|;
comment|// SDRAM Controller Interrupt Mask Register
name|AT91_REG
name|EBI_SDRC_ISR
decl_stmt|;
comment|// SDRAM Controller Interrupt Mask Register
name|AT91_REG
name|Reserved43
index|[
literal|3
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EBI_BFC_MR
decl_stmt|;
comment|// BFC Mode Register
block|}
name|AT91S_SYS
operator|,
typedef|*
name|AT91PS_SYS
typedef|;
end_typedef

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Memory Controller Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_MC
block|{
name|AT91_REG
name|MC_RCR
decl_stmt|;
comment|// MC Remap Control Register
name|AT91_REG
name|MC_ASR
decl_stmt|;
comment|// MC Abort Status Register
name|AT91_REG
name|MC_AASR
decl_stmt|;
comment|// MC Abort Address Status Register
name|AT91_REG
name|Reserved0
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MC_PUIA
index|[
literal|16
index|]
decl_stmt|;
comment|// MC Protection Unit Area
name|AT91_REG
name|MC_PUP
decl_stmt|;
comment|// MC Protection Unit Peripherals
name|AT91_REG
name|MC_PUER
decl_stmt|;
comment|// MC Protection Unit Enable Register
block|}
name|AT91S_MC
operator|,
typedef|*
name|AT91PS_MC
typedef|;
end_typedef

begin_comment
comment|// -------- MC_RCR : (MC Offset: 0x0) MC Remap Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_RCB
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MC) Remap Command Bit
end_comment

begin_comment
comment|// -------- MC_ASR : (MC Offset: 0x4) MC Abort Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_UNDADD
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MC) Undefined Addess Abort Status
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_MISADD
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (MC) Misaligned Addess Abort Status
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_MPU
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (MC) Memory protection Unit Abort Status
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTSZ
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (MC) Abort Size Status
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTSZ_BYTE
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (MC) Byte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTSZ_HWORD
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (MC) Half-word
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTSZ_WORD
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (MC) Word
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTTYP
value|((unsigned int) 0x3<< 10)
end_define

begin_comment
comment|// (MC) Abort Type Status
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTTYP_DATAR
value|((unsigned int) 0x0<< 10)
end_define

begin_comment
comment|// (MC) Data Read
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTTYP_DATAW
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (MC) Data Write
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ABTTYP_FETCH
value|((unsigned int) 0x2<< 10)
end_define

begin_comment
comment|// (MC) Code Fetch
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_MST0
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (MC) Master 0 Abort Source
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_MST1
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (MC) Master 1 Abort Source
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SVMST0
value|((unsigned int) 0x1<< 24)
end_define

begin_comment
comment|// (MC) Saved Master 0 Abort Source
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SVMST1
value|((unsigned int) 0x1<< 25)
end_define

begin_comment
comment|// (MC) Saved Master 1 Abort Source
end_comment

begin_comment
comment|// -------- MC_PUIA : (MC Offset: 0x10) MC Protection Unit Area --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PROT
value|((unsigned int) 0x3<<  0)
end_define

begin_comment
comment|// (MC) Protection
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PROT_PNAUNA
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (MC) Privilege: No Access, User: No Access
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PROT_PRWUNA
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (MC) Privilege: Read/Write, User: No Access
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PROT_PRWURO
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (MC) Privilege: Read/Write, User: Read Only
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PROT_PRWURW
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (MC) Privilege: Read/Write, User: Read/Write
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE
value|((unsigned int) 0xF<<  4)
end_define

begin_comment
comment|// (MC) Internal Area Size
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_1KB
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (MC) Area size 1KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_2KB
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (MC) Area size 2KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_4KB
value|((unsigned int) 0x2<<  4)
end_define

begin_comment
comment|// (MC) Area size 4KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_8KB
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (MC) Area size 8KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_16KB
value|((unsigned int) 0x4<<  4)
end_define

begin_comment
comment|// (MC) Area size 16KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_32KB
value|((unsigned int) 0x5<<  4)
end_define

begin_comment
comment|// (MC) Area size 32KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_64KB
value|((unsigned int) 0x6<<  4)
end_define

begin_comment
comment|// (MC) Area size 64KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_128KB
value|((unsigned int) 0x7<<  4)
end_define

begin_comment
comment|// (MC) Area size 128KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_256KB
value|((unsigned int) 0x8<<  4)
end_define

begin_comment
comment|// (MC) Area size 256KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_512KB
value|((unsigned int) 0x9<<  4)
end_define

begin_comment
comment|// (MC) Area size 512KByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_1MB
value|((unsigned int) 0xA<<  4)
end_define

begin_comment
comment|// (MC) Area size 1MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_2MB
value|((unsigned int) 0xB<<  4)
end_define

begin_comment
comment|// (MC) Area size 2MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_4MB
value|((unsigned int) 0xC<<  4)
end_define

begin_comment
comment|// (MC) Area size 4MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_8MB
value|((unsigned int) 0xD<<  4)
end_define

begin_comment
comment|// (MC) Area size 8MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_16MB
value|((unsigned int) 0xE<<  4)
end_define

begin_comment
comment|// (MC) Area size 16MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_SIZE_64MB
value|((unsigned int) 0xF<<  4)
end_define

begin_comment
comment|// (MC) Area size 64MByte
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_BA
value|((unsigned int) 0x3FFFF<< 10)
end_define

begin_comment
comment|// (MC) Internal Area Base Address
end_comment

begin_comment
comment|// -------- MC_PUP : (MC Offset: 0x50) MC Protection Unit Peripheral --------
end_comment

begin_comment
comment|// -------- MC_PUER : (MC Offset: 0x54) MC Protection Unit Area --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PUEB
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MC) Protection Unit enable Bit
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Real-time Clock Alarm and Parallel Load Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_RTC
block|{
name|AT91_REG
name|RTC_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|RTC_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|RTC_TIMR
decl_stmt|;
comment|// Time Register
name|AT91_REG
name|RTC_CALR
decl_stmt|;
comment|// Calendar Register
name|AT91_REG
name|RTC_TIMALR
decl_stmt|;
comment|// Time Alarm Register
name|AT91_REG
name|RTC_CALALR
decl_stmt|;
comment|// Calendar Alarm Register
name|AT91_REG
name|RTC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|RTC_SCCR
decl_stmt|;
comment|// Status Clear Command Register
name|AT91_REG
name|RTC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|RTC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|RTC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|RTC_VER
decl_stmt|;
comment|// Valid Entry Register
block|}
name|AT91S_RTC
operator|,
typedef|*
name|AT91PS_RTC
typedef|;
end_typedef

begin_comment
comment|// -------- RTC_CR : (RTC Offset: 0x0) RTC Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_UPDTIM
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (RTC) Update Request Time Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_UPDCAL
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (RTC) Update Request Calendar Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEVSEL
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (RTC) Time Event Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEVSEL_MINUTE
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (RTC) Minute change.
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEVSEL_HOUR
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (RTC) Hour change.
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEVSEL_DAY24
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (RTC) Every day at midnight.
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEVSEL_DAY12
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (RTC) Every day at noon.
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALEVSEL
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (RTC) Calendar Event Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALEVSEL_WEEK
value|((unsigned int) 0x0<< 16)
end_define

begin_comment
comment|// (RTC) Week change (every Monday at time 00:00:00).
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALEVSEL_MONTH
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (RTC) Month change (every 01 of each month at time 00:00:00).
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALEVSEL_YEAR
value|((unsigned int) 0x2<< 16)
end_define

begin_comment
comment|// (RTC) Year change (every January 1 at time 00:00:00).
end_comment

begin_comment
comment|// -------- RTC_MR : (RTC Offset: 0x4) RTC Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_HRMOD
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (RTC) 12-24 hour Mode
end_comment

begin_comment
comment|// -------- RTC_TIMR : (RTC Offset: 0x8) RTC Time Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_SEC
value|((unsigned int) 0x7F<<  0)
end_define

begin_comment
comment|// (RTC) Current Second
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_MIN
value|((unsigned int) 0x7F<<  8)
end_define

begin_comment
comment|// (RTC) Current Minute
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_HOUR
value|((unsigned int) 0x1F<< 16)
end_define

begin_comment
comment|// (RTC) Current Hour
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_AMPM
value|((unsigned int) 0x1<< 22)
end_define

begin_comment
comment|// (RTC) Ante Meridiem, Post Meridiem Indicator
end_comment

begin_comment
comment|// -------- RTC_CALR : (RTC Offset: 0xc) RTC Calendar Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CENT
value|((unsigned int) 0x3F<<  0)
end_define

begin_comment
comment|// (RTC) Current Century
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_YEAR
value|((unsigned int) 0xFF<<  8)
end_define

begin_comment
comment|// (RTC) Current Year
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_MONTH
value|((unsigned int) 0x1F<< 16)
end_define

begin_comment
comment|// (RTC) Current Month
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_DAY
value|((unsigned int) 0x7<< 21)
end_define

begin_comment
comment|// (RTC) Current Day
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_DATE
value|((unsigned int) 0x3F<< 24)
end_define

begin_comment
comment|// (RTC) Current Date
end_comment

begin_comment
comment|// -------- RTC_TIMALR : (RTC Offset: 0x10) RTC Time Alarm Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_SECEN
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (RTC) Second Alarm Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_MINEN
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (RTC) Minute Alarm
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_HOUREN
value|((unsigned int) 0x1<< 23)
end_define

begin_comment
comment|// (RTC) Current Hour
end_comment

begin_comment
comment|// -------- RTC_CALALR : (RTC Offset: 0x14) RTC Calendar Alarm Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_MONTHEN
value|((unsigned int) 0x1<< 23)
end_define

begin_comment
comment|// (RTC) Month Alarm Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_DATEEN
value|((unsigned int) 0x1<< 31)
end_define

begin_comment
comment|// (RTC) Date Alarm Enable
end_comment

begin_comment
comment|// -------- RTC_SR : (RTC Offset: 0x18) RTC Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_ACKUPD
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (RTC) Acknowledge for Update
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_ALARM
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (RTC) Alarm Flag
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_SECEV
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (RTC) Second Event
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMEV
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (RTC) Time Event
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALEV
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (RTC) Calendar event
end_comment

begin_comment
comment|// -------- RTC_SCCR : (RTC Offset: 0x1c) RTC Status Clear Command Register --------
end_comment

begin_comment
comment|// -------- RTC_IER : (RTC Offset: 0x20) RTC Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- RTC_IDR : (RTC Offset: 0x24) RTC Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- RTC_IMR : (RTC Offset: 0x28) RTC Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- RTC_VER : (RTC Offset: 0x2c) RTC Valid Entry Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_NVTIM
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (RTC) Non valid Time
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_NVCAL
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (RTC) Non valid Calendar
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_NVTIMALR
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (RTC) Non valid time Alarm
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_NVCALALR
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (RTC) Nonvalid Calendar Alarm
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR System Timer Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_ST
block|{
name|AT91_REG
name|ST_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|ST_PIMR
decl_stmt|;
comment|// Period Interval Mode Register
name|AT91_REG
name|ST_WDMR
decl_stmt|;
comment|// Watchdog Mode Register
name|AT91_REG
name|ST_RTMR
decl_stmt|;
comment|// Real-time Mode Register
name|AT91_REG
name|ST_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|ST_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|ST_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|ST_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|ST_RTAR
decl_stmt|;
comment|// Real-time Alarm Register
name|AT91_REG
name|ST_CRTR
decl_stmt|;
comment|// Current Real-time Register
block|}
name|AT91S_ST
operator|,
typedef|*
name|AT91PS_ST
typedef|;
end_typedef

begin_comment
comment|// -------- ST_CR : (ST Offset: 0x0) System Timer Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_WDRST
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (ST) Watchdog Timer Restart
end_comment

begin_comment
comment|// -------- ST_PIMR : (ST Offset: 0x4) System Timer Period Interval Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_PIV
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (ST) Watchdog Timer Restart
end_comment

begin_comment
comment|// -------- ST_WDMR : (ST Offset: 0x8) System Timer Watchdog Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_WDV
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (ST) Watchdog Timer Restart
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_RSTEN
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (ST) Reset Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_EXTEN
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (ST) External Signal Assertion Enable
end_comment

begin_comment
comment|// -------- ST_RTMR : (ST Offset: 0xc) System Timer Real-time Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_RTPRES
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (ST) Real-time Timer Prescaler Value
end_comment

begin_comment
comment|// -------- ST_SR : (ST Offset: 0x10) System Timer Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_PITS
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (ST) Period Interval Timer Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_WDOVF
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (ST) Watchdog Overflow
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_RTTINC
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (ST) Real-time Timer Increment
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_ALMS
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (ST) Alarm Status
end_comment

begin_comment
comment|// -------- ST_IER : (ST Offset: 0x14) System Timer Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- ST_IDR : (ST Offset: 0x18) System Timer Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- ST_IMR : (ST Offset: 0x1c) System Timer Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- ST_RTAR : (ST Offset: 0x20) System Timer Real-time Alarm Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_ALMV
value|((unsigned int) 0xFFFFF<<  0)
end_define

begin_comment
comment|// (ST) Alarm Value Value
end_comment

begin_comment
comment|// -------- ST_CRTR : (ST Offset: 0x24) System Timer Current Real-time Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_CRTV
value|((unsigned int) 0xFFFFF<<  0)
end_define

begin_comment
comment|// (ST) Current Real-time Value
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Power Management Controler
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_PMC
block|{
name|AT91_REG
name|PMC_SCER
decl_stmt|;
comment|// System Clock Enable Register
name|AT91_REG
name|PMC_SCDR
decl_stmt|;
comment|// System Clock Disable Register
name|AT91_REG
name|PMC_SCSR
decl_stmt|;
comment|// System Clock Status Register
name|AT91_REG
name|Reserved0
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_PCER
decl_stmt|;
comment|// Peripheral Clock Enable Register
name|AT91_REG
name|PMC_PCDR
decl_stmt|;
comment|// Peripheral Clock Disable Register
name|AT91_REG
name|PMC_PCSR
decl_stmt|;
comment|// Peripheral Clock Status Register
name|AT91_REG
name|Reserved1
index|[
literal|5
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_MCKR
decl_stmt|;
comment|// Master Clock Register
name|AT91_REG
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PMC_PCKR
index|[
literal|8
index|]
decl_stmt|;
comment|// Programmable Clock Register
name|AT91_REG
name|PMC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PMC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PMC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|PMC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
block|}
name|AT91S_PMC
operator|,
typedef|*
name|AT91PS_PMC
typedef|;
end_typedef

begin_comment
comment|// -------- PMC_SCER : (PMC Offset: 0x0) System Clock Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (PMC) Processor Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_UDP
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (PMC) USB Device Port Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MCKUDP
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (PMC) USB Device Port Master Clock Automatic Disable on Suspend
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_UHP
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (PMC) USB Host Port Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK0
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK1
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK2
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK3
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK4
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK5
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK6
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK7
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (PMC) Programmable Clock Output
end_comment

begin_comment
comment|// -------- PMC_SCDR : (PMC Offset: 0x4) System Clock Disable Register --------
end_comment

begin_comment
comment|// -------- PMC_SCSR : (PMC Offset: 0x8) System Clock Status Register --------
end_comment

begin_comment
comment|// -------- PMC_MCKR : (PMC Offset: 0x30) Master Clock Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_CSS
value|((unsigned int) 0x3<<  0)
end_define

begin_comment
comment|// (PMC) Programmable Clock Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_CSS_SLOW_CLK
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (PMC) Slow Clock is selected
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_CSS_MAIN_CLK
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (PMC) Main Clock is selected
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_CSS_PLLA_CLK
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (PMC) Clock from PLL A is selected
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_CSS_PLLB_CLK
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (PMC) Clock from PLL B is selected
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES
value|((unsigned int) 0x7<<  2)
end_define

begin_comment
comment|// (PMC) Programmable Clock Prescaler
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK
value|((unsigned int) 0x0<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_2
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_4
value|((unsigned int) 0x2<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_8
value|((unsigned int) 0x3<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_16
value|((unsigned int) 0x4<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 16
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_32
value|((unsigned int) 0x5<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 32
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PRES_CLK_64
value|((unsigned int) 0x6<<  2)
end_define

begin_comment
comment|// (PMC) Selected clock divided by 64
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MDIV
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (PMC) Master Clock Division
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MDIV_1
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (PMC) The master clock and the processor clock are the same
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MDIV_2
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (PMC) The processor clock is twice as fast as the master clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MDIV_3
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (PMC) The processor clock is three times faster than the master clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MDIV_4
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (PMC) The processor clock is four times faster than the master clock
end_comment

begin_comment
comment|// -------- PMC_PCKR : (PMC Offset: 0x40) Programmable Clock Register --------
end_comment

begin_comment
comment|// -------- PMC_IER : (PMC Offset: 0x60) PMC Interrupt Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MOSCS
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (PMC) MOSC Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_LOCKA
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (PMC) PLL A Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_LOCKB
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (PMC) PLL B Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MCKRDY
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (PMC) MCK_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK0RDY
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (PMC) PCK0_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK1RDY
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (PMC) PCK1_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK2RDY
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (PMC) PCK2_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK3RDY
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (PMC) PCK3_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK4RDY
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (PMC) PCK4_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK5RDY
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (PMC) PCK5_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK6RDY
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (PMC) PCK6_RDY Status/Enable/Disable/Mask
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCK7RDY
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (PMC) PCK7_RDY Status/Enable/Disable/Mask
end_comment

begin_comment
comment|// -------- PMC_IDR : (PMC Offset: 0x64) PMC Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- PMC_SR : (PMC Offset: 0x68) PMC Status Register --------
end_comment

begin_comment
comment|// -------- PMC_IMR : (PMC Offset: 0x6c) PMC Interrupt Mask Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Clock Generator Controler
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_CKGR
block|{
name|AT91_REG
name|CKGR_MOR
decl_stmt|;
comment|// Main Oscillator Register
name|AT91_REG
name|CKGR_MCFR
decl_stmt|;
comment|// Main Clock  Frequency Register
name|AT91_REG
name|CKGR_PLLAR
decl_stmt|;
comment|// PLL A Register
name|AT91_REG
name|CKGR_PLLBR
decl_stmt|;
comment|// PLL B Register
block|}
name|AT91S_CKGR
operator|,
typedef|*
name|AT91PS_CKGR
typedef|;
end_typedef

begin_comment
comment|// -------- CKGR_MOR : (CKGR Offset: 0x0) Main Oscillator Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MOSCEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (CKGR) Main Oscillator Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OSCTEST
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (CKGR) Oscillator Test
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OSCOUNT
value|((unsigned int) 0xFF<<  8)
end_define

begin_comment
comment|// (CKGR) Main Oscillator Start-up Time
end_comment

begin_comment
comment|// -------- CKGR_MCFR : (CKGR Offset: 0x4) Main Clock Frequency Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MAINF
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (CKGR) Main Clock Frequency
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MAINRDY
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (CKGR) Main Clock Ready
end_comment

begin_comment
comment|// -------- CKGR_PLLAR : (CKGR Offset: 0x8) PLL A Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVA
value|((unsigned int) 0xFF<<  0)
end_define

begin_comment
comment|// (CKGR) Divider Selected
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVA_0
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (CKGR) Divider output is 0
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVA_BYPASS
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (CKGR) Divider is bypassed
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_PLLACOUNT
value|((unsigned int) 0x3F<<  8)
end_define

begin_comment
comment|// (CKGR) PLL A Counter
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTA
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (CKGR) PLL A Output Frequency Range
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTA_0
value|((unsigned int) 0x0<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLA datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTA_1
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLA datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTA_2
value|((unsigned int) 0x2<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLA datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTA_3
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLA datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MULA
value|((unsigned int) 0x7FF<< 16)
end_define

begin_comment
comment|// (CKGR) PLL A Multiplier
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_SRCA
value|((unsigned int) 0x1<< 29)
end_define

begin_comment
comment|// (CKGR) PLL A Source
end_comment

begin_comment
comment|// -------- CKGR_PLLBR : (CKGR Offset: 0xc) PLL B Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVB
value|((unsigned int) 0xFF<<  0)
end_define

begin_comment
comment|// (CKGR) Divider Selected
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVB_0
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (CKGR) Divider output is 0
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_DIVB_BYPASS
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (CKGR) Divider is bypassed
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_PLLBCOUNT
value|((unsigned int) 0x3F<<  8)
end_define

begin_comment
comment|// (CKGR) PLL B Counter
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTB
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (CKGR) PLL B Output Frequency Range
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTB_0
value|((unsigned int) 0x0<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLB datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTB_1
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLB datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTB_2
value|((unsigned int) 0x2<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLB datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_OUTB_3
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (CKGR) Please refer to the PLLB datasheet
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MULB
value|((unsigned int) 0x7FF<< 16)
end_define

begin_comment
comment|// (CKGR) PLL B Multiplier
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_USB_96M
value|((unsigned int) 0x1<< 28)
end_define

begin_comment
comment|// (CKGR) Divider for USB Ports
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_USB_PLL
value|((unsigned int) 0x1<< 29)
end_define

begin_comment
comment|// (CKGR) PLL Use
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Parallel Input Output Controler
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_PIO
block|{
name|AT91_REG
name|PIO_PER
decl_stmt|;
comment|// PIO Enable Register
name|AT91_REG
name|PIO_PDR
decl_stmt|;
comment|// PIO Disable Register
name|AT91_REG
name|PIO_PSR
decl_stmt|;
comment|// PIO Status Register
name|AT91_REG
name|Reserved0
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_OER
decl_stmt|;
comment|// Output Enable Register
name|AT91_REG
name|PIO_ODR
decl_stmt|;
comment|// Output Disable Registerr
name|AT91_REG
name|PIO_OSR
decl_stmt|;
comment|// Output Status Register
name|AT91_REG
name|Reserved1
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_IFER
decl_stmt|;
comment|// Input Filter Enable Register
name|AT91_REG
name|PIO_IFDR
decl_stmt|;
comment|// Input Filter Disable Register
name|AT91_REG
name|PIO_IFSR
decl_stmt|;
comment|// Input Filter Status Register
name|AT91_REG
name|Reserved2
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_SODR
decl_stmt|;
comment|// Set Output Data Register
name|AT91_REG
name|PIO_CODR
decl_stmt|;
comment|// Clear Output Data Register
name|AT91_REG
name|PIO_ODSR
decl_stmt|;
comment|// Output Data Status Register
name|AT91_REG
name|PIO_PDSR
decl_stmt|;
comment|// Pin Data Status Register
name|AT91_REG
name|PIO_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|PIO_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|PIO_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|PIO_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|PIO_MDER
decl_stmt|;
comment|// Multi-driver Enable Register
name|AT91_REG
name|PIO_MDDR
decl_stmt|;
comment|// Multi-driver Disable Register
name|AT91_REG
name|PIO_MDSR
decl_stmt|;
comment|// Multi-driver Status Register
name|AT91_REG
name|Reserved3
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_PPUDR
decl_stmt|;
comment|// Pull-up Disable Register
name|AT91_REG
name|PIO_PPUER
decl_stmt|;
comment|// Pull-up Enable Register
name|AT91_REG
name|PIO_PPUSR
decl_stmt|;
comment|// Pad Pull-up Status Register
name|AT91_REG
name|Reserved4
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_ASR
decl_stmt|;
comment|// Select A Register
name|AT91_REG
name|PIO_BSR
decl_stmt|;
comment|// Select B Register
name|AT91_REG
name|PIO_ABSR
decl_stmt|;
comment|// AB Select Status Register
name|AT91_REG
name|Reserved5
index|[
literal|9
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|PIO_OWER
decl_stmt|;
comment|// Output Write Enable Register
name|AT91_REG
name|PIO_OWDR
decl_stmt|;
comment|// Output Write Disable Register
name|AT91_REG
name|PIO_OWSR
decl_stmt|;
comment|// Output Write Status Register
block|}
name|AT91S_PIO
operator|,
typedef|*
name|AT91PS_PIO
typedef|;
end_typedef

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Debug Unit
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_DBGU
block|{
name|AT91_REG
name|DBGU_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|DBGU_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|DBGU_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|DBGU_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|DBGU_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|DBGU_CSR
decl_stmt|;
comment|// Channel Status Register
name|AT91_REG
name|DBGU_RHR
decl_stmt|;
comment|// Receiver Holding Register
name|AT91_REG
name|DBGU_THR
decl_stmt|;
comment|// Transmitter Holding Register
name|AT91_REG
name|DBGU_BRGR
decl_stmt|;
comment|// Baud Rate Generator Register
name|AT91_REG
name|Reserved0
index|[
literal|7
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|DBGU_C1R
decl_stmt|;
comment|// Chip ID1 Register
name|AT91_REG
name|DBGU_C2R
decl_stmt|;
comment|// Chip ID2 Register
name|AT91_REG
name|DBGU_FNTR
decl_stmt|;
comment|// Force NTRST Register
name|AT91_REG
name|Reserved1
index|[
literal|45
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|DBGU_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|DBGU_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|DBGU_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|DBGU_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|DBGU_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|DBGU_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|DBGU_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|DBGU_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|DBGU_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|DBGU_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_DBGU
operator|,
typedef|*
name|AT91PS_DBGU
typedef|;
end_typedef

begin_comment
comment|// -------- DBGU_CR : (DBGU Offset: 0x0) Debug Unit Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RSTRX
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (DBGU) Reset Receiver
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RSTTX
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (DBGU) Reset Transmitter
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RXEN
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (DBGU) Receiver Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RXDIS
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (DBGU) Receiver Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TXEN
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (DBGU) Transmitter Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TXDIS
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (DBGU) Transmitter Disable
end_comment

begin_comment
comment|// -------- DBGU_MR : (DBGU Offset: 0x4) Debug Unit Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR
value|((unsigned int) 0x7<<  9)
end_define

begin_comment
comment|// (DBGU) Parity type
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_EVEN
value|((unsigned int) 0x0<<  9)
end_define

begin_comment
comment|// (DBGU) Even Parity
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_ODD
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (DBGU) Odd Parity
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_SPACE
value|((unsigned int) 0x2<<  9)
end_define

begin_comment
comment|// (DBGU) Parity forced to 0 (Space)
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_MARK
value|((unsigned int) 0x3<<  9)
end_define

begin_comment
comment|// (DBGU) Parity forced to 1 (Mark)
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_NONE
value|((unsigned int) 0x4<<  9)
end_define

begin_comment
comment|// (DBGU) No Parity
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PAR_MULTI_DROP
value|((unsigned int) 0x6<<  9)
end_define

begin_comment
comment|// (DBGU) Multi-drop mode
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHMODE
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (DBGU) Channel Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHMODE_NORMAL
value|((unsigned int) 0x0<< 14)
end_define

begin_comment
comment|// (DBGU) Normal Mode: The USART channel operates as an RX/TX USART.
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHMODE_AUTO
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (DBGU) Automatic Echo: Receiver Data Input is connected to the TXD pin.
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHMODE_LOCAL
value|((unsigned int) 0x2<< 14)
end_define

begin_comment
comment|// (DBGU) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal.
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHMODE_REMOTE
value|((unsigned int) 0x3<< 14)
end_define

begin_comment
comment|// (DBGU) Remote Loopback: RXD pin is internally connected to TXD pin.
end_comment

begin_comment
comment|// -------- DBGU_IER : (DBGU Offset: 0x8) Debug Unit Interrupt Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RXRDY
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (DBGU) RXRDY Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TXRDY
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (DBGU) TXRDY Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_ENDRX
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (DBGU) End of Receive Transfer Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_ENDTX
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (DBGU) End of Transmit Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_OVRE
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (DBGU) Overrun Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_FRAME
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (DBGU) Framing Error Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_PARE
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (DBGU) Parity Error Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TXEMPTY
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (DBGU) TXEMPTY Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TXBUFE
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (DBGU) TXBUFE Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RXBUFF
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (DBGU) RXBUFF Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_COMM_TX
value|((unsigned int) 0x1<< 30)
end_define

begin_comment
comment|// (DBGU) COMM_TX Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_US_COMM_RX
value|((unsigned int) 0x1<< 31)
end_define

begin_comment
comment|// (DBGU) COMM_RX Interrupt
end_comment

begin_comment
comment|// -------- DBGU_IDR : (DBGU Offset: 0xc) Debug Unit Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- DBGU_IMR : (DBGU Offset: 0x10) Debug Unit Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- DBGU_CSR : (DBGU Offset: 0x14) Debug Unit Channel Status Register --------
end_comment

begin_comment
comment|// -------- DBGU_FNTR : (DBGU Offset: 0x48) Debug Unit FORCE_NTRST Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_FORCE_NTRST
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (DBGU) Force NTRST in JTAG
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Peripheral Data Controller
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_PDC
block|{
name|AT91_REG
name|PDC_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|PDC_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|PDC_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|PDC_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|PDC_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|PDC_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|PDC_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|PDC_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|PDC_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|PDC_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_PDC
operator|,
typedef|*
name|AT91PS_PDC
typedef|;
end_typedef

begin_comment
comment|// -------- PDC_PTCR : (PDC Offset: 0x20) PDC Transfer Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_PDC_RXTEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (PDC) Receiver Transfer Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PDC_RXTDIS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (PDC) Receiver Transfer Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_PDC_TXTEN
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (PDC) Transmitter Transfer Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PDC_TXTDIS
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (PDC) Transmitter Transfer Disable
end_comment

begin_comment
comment|// -------- PDC_PTSR : (PDC Offset: 0x24) PDC Transfer Status Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Advanced Interrupt Controller
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_AIC
block|{
name|AT91_REG
name|AIC_SMR
index|[
literal|32
index|]
decl_stmt|;
comment|// Source Mode Register
name|AT91_REG
name|AIC_SVR
index|[
literal|32
index|]
decl_stmt|;
comment|// Source Vector Register
name|AT91_REG
name|AIC_IVR
decl_stmt|;
comment|// IRQ Vector Register
name|AT91_REG
name|AIC_FVR
decl_stmt|;
comment|// FIQ Vector Register
name|AT91_REG
name|AIC_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|AIC_IPR
decl_stmt|;
comment|// Interrupt Pending Register
name|AT91_REG
name|AIC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|AIC_CISR
decl_stmt|;
comment|// Core Interrupt Status Register
name|AT91_REG
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|AIC_IECR
decl_stmt|;
comment|// Interrupt Enable Command Register
name|AT91_REG
name|AIC_IDCR
decl_stmt|;
comment|// Interrupt Disable Command Register
name|AT91_REG
name|AIC_ICCR
decl_stmt|;
comment|// Interrupt Clear Command Register
name|AT91_REG
name|AIC_ISCR
decl_stmt|;
comment|// Interrupt Set Command Register
name|AT91_REG
name|AIC_EOICR
decl_stmt|;
comment|// End of Interrupt Command Register
name|AT91_REG
name|AIC_SPU
decl_stmt|;
comment|// Spurious Vector Register
name|AT91_REG
name|AIC_DCR
decl_stmt|;
comment|// Debug Control Register (Protect)
name|AT91_REG
name|Reserved1
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|AIC_FFER
decl_stmt|;
comment|// Fast Forcing Enable Register
name|AT91_REG
name|AIC_FFDR
decl_stmt|;
comment|// Fast Forcing Disable Register
name|AT91_REG
name|AIC_FFSR
decl_stmt|;
comment|// Fast Forcing Status Register
block|}
name|AT91S_AIC
operator|,
typedef|*
name|AT91PS_AIC
typedef|;
end_typedef

begin_comment
comment|// -------- AIC_SMR : (AIC Offset: 0x0) Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_PRIOR
value|((unsigned int) 0x7<<  0)
end_define

begin_comment
comment|// (AIC) Priority Level
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_PRIOR_LOWEST
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (AIC) Lowest priority level
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_PRIOR_HIGHEST
value|((unsigned int) 0x7)
end_define

begin_comment
comment|// (AIC) Highest priority level
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SRCTYPE
value|((unsigned int) 0x3<<  5)
end_define

begin_comment
comment|// (AIC) Interrupt Source Type
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE
value|((unsigned int) 0x0<<  5)
end_define

begin_comment
comment|// (AIC) Internal Sources Code Label Level Sensitive
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SRCTYPE_INT_EDGE_TRIGGERED
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (AIC) Internal Sources Code Label Edge triggered
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SRCTYPE_EXT_HIGH_LEVEL
value|((unsigned int) 0x2<<  5)
end_define

begin_comment
comment|// (AIC) External Sources Code Label High-level Sensitive
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SRCTYPE_EXT_POSITIVE_EDGE
value|((unsigned int) 0x3<<  5)
end_define

begin_comment
comment|// (AIC) External Sources Code Label Positive Edge triggered
end_comment

begin_comment
comment|// -------- AIC_CISR : (AIC Offset: 0x114) AIC Core Interrupt Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_NFIQ
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (AIC) NFIQ Status
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_NIRQ
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (AIC) NIRQ Status
end_comment

begin_comment
comment|// -------- AIC_DCR : (AIC Offset: 0x138) AIC Debug Control Register (Protect) --------
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_DCR_PROT
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (AIC) Protection Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_DCR_GMSK
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (AIC) General Mask
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Serial Parallel Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_SPI
block|{
name|AT91_REG
name|SPI_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|SPI_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|SPI_RDR
decl_stmt|;
comment|// Receive Data Register
name|AT91_REG
name|SPI_TDR
decl_stmt|;
comment|// Transmit Data Register
name|AT91_REG
name|SPI_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|SPI_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|SPI_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|SPI_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|Reserved0
index|[
literal|4
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|SPI_CSR
index|[
literal|4
index|]
decl_stmt|;
comment|// Chip Select Register
name|AT91_REG
name|Reserved1
index|[
literal|48
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|SPI_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|SPI_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|SPI_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|SPI_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|SPI_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|SPI_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|SPI_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|SPI_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|SPI_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|SPI_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_SPI
operator|,
typedef|*
name|AT91PS_SPI
typedef|;
end_typedef

begin_comment
comment|// -------- SPI_CR : (SPI Offset: 0x0) SPI Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SPIEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SPI) SPI Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SPIDIS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SPI) SPI Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SWRST
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SPI) SPI Software reset
end_comment

begin_comment
comment|// -------- SPI_MR : (SPI Offset: 0x4) SPI Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_MSTR
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SPI) Master/Slave Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SPI) Peripheral Select
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PS_FIXED
value|((unsigned int) 0x0<<  1)
end_define

begin_comment
comment|// (SPI) Fixed Peripheral Select
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PS_VARIABLE
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SPI) Variable Peripheral Select
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PCSDEC
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (SPI) Chip Select Decode
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_DIV32
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (SPI) Clock Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_MODFDIS
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SPI) Mode Fault Detection
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_LLB
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SPI) Clock Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PCS
value|((unsigned int) 0xF<< 16)
end_define

begin_comment
comment|// (SPI) Peripheral Chip Select
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_DLYBCS
value|((unsigned int) 0xFF<< 24)
end_define

begin_comment
comment|// (SPI) Delay Between Chip Selects
end_comment

begin_comment
comment|// -------- SPI_RDR : (SPI Offset: 0x8) Receive Data Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RD
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (SPI) Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RPCS
value|((unsigned int) 0xF<< 16)
end_define

begin_comment
comment|// (SPI) Peripheral Chip Select Status
end_comment

begin_comment
comment|// -------- SPI_TDR : (SPI Offset: 0xc) Transmit Data Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TD
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (SPI) Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TPCS
value|((unsigned int) 0xF<< 16)
end_define

begin_comment
comment|// (SPI) Peripheral Chip Select Status
end_comment

begin_comment
comment|// -------- SPI_SR : (SPI Offset: 0x10) Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RDRF
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SPI) Receive Data Register Full
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TDRE
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SPI) Transmit Data Register Empty
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_MODF
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (SPI) Mode Fault Error
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_OVRES
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (SPI) Overrun Error Status
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SPENDRX
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SPI) End of Receiver Transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SPENDTX
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (SPI) End of Receiver Transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RXBUFF
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (SPI) RXBUFF Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TXBUFE
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SPI) TXBUFE Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SPIENS
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (SPI) Enable Status
end_comment

begin_comment
comment|// -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- SPI_IMR : (SPI Offset: 0x1c) Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- SPI_CSR : (SPI Offset: 0x30) Chip Select Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_CPOL
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SPI) Clock Polarity
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_NCPHA
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SPI) Clock Phase
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS
value|((unsigned int) 0xF<<  4)
end_define

begin_comment
comment|// (SPI) Bits Per Transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_8
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (SPI) 8 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_9
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SPI) 9 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_10
value|((unsigned int) 0x2<<  4)
end_define

begin_comment
comment|// (SPI) 10 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_11
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (SPI) 11 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_12
value|((unsigned int) 0x4<<  4)
end_define

begin_comment
comment|// (SPI) 12 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_13
value|((unsigned int) 0x5<<  4)
end_define

begin_comment
comment|// (SPI) 13 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_14
value|((unsigned int) 0x6<<  4)
end_define

begin_comment
comment|// (SPI) 14 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_15
value|((unsigned int) 0x7<<  4)
end_define

begin_comment
comment|// (SPI) 15 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_BITS_16
value|((unsigned int) 0x8<<  4)
end_define

begin_comment
comment|// (SPI) 16 Bits Per transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SCBR
value|((unsigned int) 0xFF<<  8)
end_define

begin_comment
comment|// (SPI) Serial Clock Baud Rate
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_DLYBS
value|((unsigned int) 0xFF<< 16)
end_define

begin_comment
comment|// (SPI) Serial Clock Baud Rate
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_DLYBCT
value|((unsigned int) 0xFF<< 24)
end_define

begin_comment
comment|// (SPI) Delay Between Consecutive Transfers
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Synchronous Serial Controller Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_SSC
block|{
name|AT91_REG
name|SSC_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|SSC_CMR
decl_stmt|;
comment|// Clock Mode Register
name|AT91_REG
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|SSC_RCMR
decl_stmt|;
comment|// Receive Clock ModeRegister
name|AT91_REG
name|SSC_RFMR
decl_stmt|;
comment|// Receive Frame Mode Register
name|AT91_REG
name|SSC_TCMR
decl_stmt|;
comment|// Transmit Clock Mode Register
name|AT91_REG
name|SSC_TFMR
decl_stmt|;
comment|// Transmit Frame Mode Register
name|AT91_REG
name|SSC_RHR
decl_stmt|;
comment|// Receive Holding Register
name|AT91_REG
name|SSC_THR
decl_stmt|;
comment|// Transmit Holding Register
name|AT91_REG
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|SSC_RSHR
decl_stmt|;
comment|// Receive Sync Holding Register
name|AT91_REG
name|SSC_TSHR
decl_stmt|;
comment|// Transmit Sync Holding Register
name|AT91_REG
name|SSC_RC0R
decl_stmt|;
comment|// Receive Compare 0 Register
name|AT91_REG
name|SSC_RC1R
decl_stmt|;
comment|// Receive Compare 1 Register
name|AT91_REG
name|SSC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|SSC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|SSC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|SSC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|Reserved2
index|[
literal|44
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|SSC_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|SSC_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|SSC_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|SSC_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|SSC_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|SSC_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|SSC_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|SSC_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|SSC_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|SSC_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_SSC
operator|,
typedef|*
name|AT91PS_SSC
typedef|;
end_typedef

begin_comment
comment|// -------- SSC_CR : (SSC Offset: 0x0) SSC Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SSC) Receive Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXDIS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SSC) Receive Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXEN
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (SSC) Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXDIS
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (SSC) Transmit Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_SWRST
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (SSC) Software Reset
end_comment

begin_comment
comment|// -------- SSC_RCMR : (SSC Offset: 0x10) SSC Receive Clock Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKS
value|((unsigned int) 0x3<<  0)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKS_DIV
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (SSC) Divided Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKS_TK
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (SSC) TK Clock signal
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKS_RK
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (SSC) RK pin
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKO
value|((unsigned int) 0x7<<  2)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Output Mode Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKO_NONE
value|((unsigned int) 0x0<<  2)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Output Mode: None RK pin: Input-only
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKO_CONTINOUS
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (SSC) Continuous Receive/Transmit Clock RK pin: Output
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKO_DATA_TX
value|((unsigned int) 0x2<<  2)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock only during data transfers RK pin: Output
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKI
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Inversion
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKG
value|((unsigned int) 0x3<<  6)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Gating Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKG_NONE
value|((unsigned int) 0x0<<  6)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock Gating: None, continuous clock
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKG_LOW
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock enabled only if RF Low
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CKG_HIGH
value|((unsigned int) 0x2<<  6)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Clock enabled only if RF High
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START
value|((unsigned int) 0xF<<  8)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Start Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_CONTINOUS
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (SSC) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data.
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_TX
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (SSC) Transmit/Receive start
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_LOW_RF
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (SSC) Detection of a low level on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_HIGH_RF
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (SSC) Detection of a high level on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_FALL_RF
value|((unsigned int) 0x4<<  8)
end_define

begin_comment
comment|// (SSC) Detection of a falling edge on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_RISE_RF
value|((unsigned int) 0x5<<  8)
end_define

begin_comment
comment|// (SSC) Detection of a rising edge on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_LEVEL_RF
value|((unsigned int) 0x6<<  8)
end_define

begin_comment
comment|// (SSC) Detection of any level change on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_EDGE_RF
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (SSC) Detection of any edge on RF input
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_START_0
value|((unsigned int) 0x8<<  8)
end_define

begin_comment
comment|// (SSC) Compare 0
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_STOP
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (SSC) Receive Stop Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_STTOUT
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Start Output Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_STTDLY
value|((unsigned int) 0xFF<< 16)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Start Delay
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_PERIOD
value|((unsigned int) 0xFF<< 24)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Period Divider Selection
end_comment

begin_comment
comment|// -------- SSC_RFMR : (SSC Offset: 0x14) SSC Receive Frame Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_DATLEN
value|((unsigned int) 0x1F<<  0)
end_define

begin_comment
comment|// (SSC) Data Length
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_LOOP
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (SSC) Loop Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_MSBF
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SSC) Most Significant Bit First
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_DATNB
value|((unsigned int) 0xF<<  8)
end_define

begin_comment
comment|// (SSC) Data Number per Frame
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSLEN
value|((unsigned int) 0xF<< 16)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Frame Sync length
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS
value|((unsigned int) 0x7<< 20)
end_define

begin_comment
comment|// (SSC) Receive/Transmit Frame Sync Output Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_NONE
value|((unsigned int) 0x0<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: None RK pin Input-only
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_NEGATIVE
value|((unsigned int) 0x1<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: Negative Pulse
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_POSITIVE
value|((unsigned int) 0x2<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: Positive Pulse
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_LOW
value|((unsigned int) 0x3<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: Driver Low during data transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_HIGH
value|((unsigned int) 0x4<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: Driver High during data transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSOS_TOGGLE
value|((unsigned int) 0x5<< 20)
end_define

begin_comment
comment|// (SSC) Selected Receive/Transmit Frame Sync Signal: Toggling at each start of data transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSEDGE
value|((unsigned int) 0x1<< 24)
end_define

begin_comment
comment|// (SSC) Frame Sync Edge Detection
end_comment

begin_comment
comment|// -------- SSC_TCMR : (SSC Offset: 0x18) SSC Transmit Clock Mode Register --------
end_comment

begin_comment
comment|// -------- SSC_TFMR : (SSC Offset: 0x1c) SSC Transmit Frame Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_DATDEF
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (SSC) Data Default Value
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_FSDEN
value|((unsigned int) 0x1<< 23)
end_define

begin_comment
comment|// (SSC) Frame Sync Data Enable
end_comment

begin_comment
comment|// -------- SSC_SR : (SSC Offset: 0x40) SSC Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXRDY
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SSC) Transmit Ready
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXEMPTY
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (SSC) Transmit Empty
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_ENDTX
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (SSC) End Of Transmission
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXBUFE
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (SSC) Transmit Buffer Empty
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXRDY
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SSC) Receive Ready
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_OVRUN
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (SSC) Receive Overrun
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_ENDRX
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (SSC) End of Reception
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXBUFF
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SSC) Receive Buffer Full
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CP0
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (SSC) Compare 0
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_CP1
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (SSC) Compare 1
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXSYN
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (SSC) Transmit Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXSYN
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (SSC) Receive Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_TXENA
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (SSC) Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC_RXENA
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (SSC) Receive Enable
end_comment

begin_comment
comment|// -------- SSC_IER : (SSC Offset: 0x44) SSC Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- SSC_IDR : (SSC Offset: 0x48) SSC Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- SSC_IMR : (SSC Offset: 0x4c) SSC Interrupt Mask Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Usart
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_USART
block|{
name|AT91_REG
name|US_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|US_MR
decl_stmt|;
comment|// Mode Register
name|AT91_REG
name|US_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|US_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|US_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|US_CSR
decl_stmt|;
comment|// Channel Status Register
name|AT91_REG
name|US_RHR
decl_stmt|;
comment|// Receiver Holding Register
name|AT91_REG
name|US_THR
decl_stmt|;
comment|// Transmitter Holding Register
name|AT91_REG
name|US_BRGR
decl_stmt|;
comment|// Baud Rate Generator Register
name|AT91_REG
name|US_RTOR
decl_stmt|;
comment|// Receiver Time-out Register
name|AT91_REG
name|US_TTGR
decl_stmt|;
comment|// Transmitter Time-guard Register
name|AT91_REG
name|Reserved0
index|[
literal|5
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|US_FIDI
decl_stmt|;
comment|// FI_DI_Ratio Register
name|AT91_REG
name|US_NER
decl_stmt|;
comment|// Nb Errors Register
name|AT91_REG
name|US_XXR
decl_stmt|;
comment|// XON_XOFF Register
name|AT91_REG
name|US_IF
decl_stmt|;
comment|// IRDA_FILTER Register
name|AT91_REG
name|Reserved1
index|[
literal|44
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|US_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|US_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|US_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|US_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|US_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|US_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|US_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|US_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|US_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|US_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_USART
operator|,
typedef|*
name|AT91PS_USART
typedef|;
end_typedef

begin_comment
comment|// -------- US_CR : (USART Offset: 0x0) Debug Unit Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RSTSTA
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (USART) Reset Status Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_STTBRK
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (USART) Start Break
end_comment

begin_define
define|#
directive|define
name|AT91C_US_STPBRK
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (USART) Stop Break
end_comment

begin_define
define|#
directive|define
name|AT91C_US_STTTO
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (USART) Start Time-out
end_comment

begin_define
define|#
directive|define
name|AT91C_US_SENDA
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (USART) Send Address
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RSTIT
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (USART) Reset Iterations
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RSTNACK
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (USART) Reset Non Acknowledge
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RETTO
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (USART) Rearm Time-out
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DTREN
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (USART) Data Terminal ready Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DTRDIS
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (USART) Data Terminal ready Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RTSEN
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (USART) Request to Send enable
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RTSDIS
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (USART) Request to Send Disable
end_comment

begin_comment
comment|// -------- US_MR : (USART Offset: 0x4) Debug Unit Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE
value|((unsigned int) 0xF<<  0)
end_define

begin_comment
comment|// (USART) Usart mode
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_NORMAL
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (USART) Normal
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_RS485
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (USART) RS485
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_HWHSH
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (USART) Hardware Handshaking
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_MODEM
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (USART) Modem
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_ISO7816_0
value|((unsigned int) 0x4)
end_define

begin_comment
comment|// (USART) ISO7816 protocol: T = 0
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_ISO7816_1
value|((unsigned int) 0x6)
end_define

begin_comment
comment|// (USART) ISO7816 protocol: T = 1
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_IRDA
value|((unsigned int) 0x8)
end_define

begin_comment
comment|// (USART) IrDA
end_comment

begin_define
define|#
directive|define
name|AT91C_US_USMODE_SWHSH
value|((unsigned int) 0xC)
end_define

begin_comment
comment|// (USART) Software Handshaking
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CLKS
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (USART) Clock Selection (Baud Rate generator Input Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CLKS_CLOCK
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (USART) Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CLKS_FDIV1
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (USART) fdiv1
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CLKS_SLOW
value|((unsigned int) 0x2<<  4)
end_define

begin_comment
comment|// (USART) slow_clock (ARM)
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CLKS_EXT
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (USART) External (SCK)
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHRL
value|((unsigned int) 0x3<<  6)
end_define

begin_comment
comment|// (USART) Clock Selection (Baud Rate generator Input Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHRL_5_BITS
value|((unsigned int) 0x0<<  6)
end_define

begin_comment
comment|// (USART) Character Length: 5 bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHRL_6_BITS
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (USART) Character Length: 6 bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHRL_7_BITS
value|((unsigned int) 0x2<<  6)
end_define

begin_comment
comment|// (USART) Character Length: 7 bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CHRL_8_BITS
value|((unsigned int) 0x3<<  6)
end_define

begin_comment
comment|// (USART) Character Length: 8 bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_SYNC
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (USART) Synchronous Mode Select
end_comment

begin_define
define|#
directive|define
name|AT91C_US_NBSTOP
value|((unsigned int) 0x3<< 12)
end_define

begin_comment
comment|// (USART) Number of Stop bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_NBSTOP_1_BIT
value|((unsigned int) 0x0<< 12)
end_define

begin_comment
comment|// (USART) 1 stop bit
end_comment

begin_define
define|#
directive|define
name|AT91C_US_NBSTOP_15_BIT
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_NBSTOP_2_BIT
value|((unsigned int) 0x2<< 12)
end_define

begin_comment
comment|// (USART) 2 stop bits
end_comment

begin_define
define|#
directive|define
name|AT91C_US_MSBF
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (USART) Bit Order
end_comment

begin_define
define|#
directive|define
name|AT91C_US_MODE9
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (USART) 9-bit Character length
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CKLO
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (USART) Clock Output Select
end_comment

begin_define
define|#
directive|define
name|AT91C_US_OVER
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (USART) Over Sampling Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_US_INACK
value|((unsigned int) 0x1<< 20)
end_define

begin_comment
comment|// (USART) Inhibit Non Acknowledge
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DSNACK
value|((unsigned int) 0x1<< 21)
end_define

begin_comment
comment|// (USART) Disable Successive NACK
end_comment

begin_define
define|#
directive|define
name|AT91C_US_MAX_ITER
value|((unsigned int) 0x1<< 24)
end_define

begin_comment
comment|// (USART) Number of Repetitions
end_comment

begin_define
define|#
directive|define
name|AT91C_US_FILTER
value|((unsigned int) 0x1<< 28)
end_define

begin_comment
comment|// (USART) Receive Line Filter
end_comment

begin_comment
comment|// -------- US_IER : (USART Offset: 0x8) Debug Unit Interrupt Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RXBRK
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (USART) Break Received/End of Break
end_comment

begin_define
define|#
directive|define
name|AT91C_US_TIMEOUT
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (USART) Receiver Time-out
end_comment

begin_define
define|#
directive|define
name|AT91C_US_ITERATION
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (USART) Max number of Repetitions Reached
end_comment

begin_define
define|#
directive|define
name|AT91C_US_NACK
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (USART) Non Acknowledge
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RIIC
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (USART) Ring INdicator Input Change Flag
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DSRIC
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (USART) Data Set Ready Input Change Flag
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DCDIC
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (USART) Data Carrier Flag
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CTSIC
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (USART) Clear To Send Input Change Flag
end_comment

begin_comment
comment|// -------- US_IDR : (USART Offset: 0xc) Debug Unit Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- US_IMR : (USART Offset: 0x10) Debug Unit Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- US_CSR : (USART Offset: 0x14) Debug Unit Channel Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_US_RI
value|((unsigned int) 0x1<< 20)
end_define

begin_comment
comment|// (USART) Image of RI Input
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DSR
value|((unsigned int) 0x1<< 21)
end_define

begin_comment
comment|// (USART) Image of DSR Input
end_comment

begin_define
define|#
directive|define
name|AT91C_US_DCD
value|((unsigned int) 0x1<< 22)
end_define

begin_comment
comment|// (USART) Image of DCD Input
end_comment

begin_define
define|#
directive|define
name|AT91C_US_CTS
value|((unsigned int) 0x1<< 23)
end_define

begin_comment
comment|// (USART) Image of CTS Input
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Two-wire Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_TWI
block|{
name|AT91_REG
name|TWI_CR
decl_stmt|;
comment|// Control Register
name|AT91_REG
name|TWI_MMR
decl_stmt|;
comment|// Master Mode Register
name|AT91_REG
name|TWI_SMR
decl_stmt|;
comment|// Slave Mode Register
name|AT91_REG
name|TWI_IADR
decl_stmt|;
comment|// Internal Address Register
name|AT91_REG
name|TWI_CWGR
decl_stmt|;
comment|// Clock Waveform Generator Register
name|AT91_REG
name|Reserved0
index|[
literal|3
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|TWI_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|TWI_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|TWI_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|TWI_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|TWI_RHR
decl_stmt|;
comment|// Receive Holding Register
name|AT91_REG
name|TWI_THR
decl_stmt|;
comment|// Transmit Holding Register
block|}
name|AT91S_TWI
operator|,
typedef|*
name|AT91PS_TWI
typedef|;
end_typedef

begin_comment
comment|// -------- TWI_CR : (TWI Offset: 0x0) TWI Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_START
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TWI) Send a START Condition
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_STOP
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (TWI) Send a STOP Condition
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_MSEN
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TWI) TWI Master Transfer Enabled
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_MSDIS
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (TWI) TWI Master Transfer Disabled
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SVEN
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (TWI) TWI Slave Transfer Enabled
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SVDIS
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (TWI) TWI Slave Transfer Disabled
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SWRST
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (TWI) Software Reset
end_comment

begin_comment
comment|// -------- TWI_MMR : (TWI Offset: 0x4) TWI Master Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADRSZ
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (TWI) Internal Device Address Size
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADRSZ_NO
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (TWI) No internal device address
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADRSZ_1_BYTE
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (TWI) One-byte internal device address
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADRSZ_2_BYTE
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (TWI) Two-byte internal device address
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADRSZ_3_BYTE
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (TWI) Three-byte internal device address
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_MREAD
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (TWI) Master Read Direction
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_DADR
value|((unsigned int) 0x7F<< 16)
end_define

begin_comment
comment|// (TWI) Device Address
end_comment

begin_comment
comment|// -------- TWI_SMR : (TWI Offset: 0x8) TWI Slave Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SADR
value|((unsigned int) 0x7F<< 16)
end_define

begin_comment
comment|// (TWI) Slave Device Address
end_comment

begin_comment
comment|// -------- TWI_CWGR : (TWI Offset: 0x10) TWI Clock Waveform Generator Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_CLDIV
value|((unsigned int) 0xFF<<  0)
end_define

begin_comment
comment|// (TWI) Clock Low Divider
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_CHDIV
value|((unsigned int) 0xFF<<  8)
end_define

begin_comment
comment|// (TWI) Clock High Divider
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_CKDIV
value|((unsigned int) 0x7<< 16)
end_define

begin_comment
comment|// (TWI) Clock Divider
end_comment

begin_comment
comment|// -------- TWI_SR : (TWI Offset: 0x20) TWI Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_TXCOMP
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TWI) Transmission Completed
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_RXRDY
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (TWI) Receive holding register ReaDY
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_TXRDY
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TWI) Transmit holding register ReaDY
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SVREAD
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (TWI) Slave Read
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SVACC
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (TWI) Slave Access
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_GCACC
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (TWI) General Call Access
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_OVRE
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (TWI) Overrun Error
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_UNRE
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (TWI) Underrun Error
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_NACK
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (TWI) Not Acknowledged
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_ARBLST
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (TWI) Arbitration Lost
end_comment

begin_comment
comment|// -------- TWI_IER : (TWI Offset: 0x24) TWI Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- TWI_IDR : (TWI Offset: 0x28) TWI Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- TWI_IMR : (TWI Offset: 0x2c) TWI Interrupt Mask Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Multimedia Card Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_MCI
block|{
name|AT91_REG
name|MCI_CR
decl_stmt|;
comment|// MCI Control Register
name|AT91_REG
name|MCI_MR
decl_stmt|;
comment|// MCI Mode Register
name|AT91_REG
name|MCI_DTOR
decl_stmt|;
comment|// MCI Data Timeout Register
name|AT91_REG
name|MCI_SDCR
decl_stmt|;
comment|// MCI SD Card Register
name|AT91_REG
name|MCI_ARGR
decl_stmt|;
comment|// MCI Argument Register
name|AT91_REG
name|MCI_CMDR
decl_stmt|;
comment|// MCI Command Register
name|AT91_REG
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MCI_RSPR
index|[
literal|4
index|]
decl_stmt|;
comment|// MCI Response Register
name|AT91_REG
name|MCI_RDR
decl_stmt|;
comment|// MCI Receive Data Register
name|AT91_REG
name|MCI_TDR
decl_stmt|;
comment|// MCI Transmit Data Register
name|AT91_REG
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MCI_SR
decl_stmt|;
comment|// MCI Status Register
name|AT91_REG
name|MCI_IER
decl_stmt|;
comment|// MCI Interrupt Enable Register
name|AT91_REG
name|MCI_IDR
decl_stmt|;
comment|// MCI Interrupt Disable Register
name|AT91_REG
name|MCI_IMR
decl_stmt|;
comment|// MCI Interrupt Mask Register
name|AT91_REG
name|Reserved2
index|[
literal|44
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|MCI_RPR
decl_stmt|;
comment|// Receive Pointer Register
name|AT91_REG
name|MCI_RCR
decl_stmt|;
comment|// Receive Counter Register
name|AT91_REG
name|MCI_TPR
decl_stmt|;
comment|// Transmit Pointer Register
name|AT91_REG
name|MCI_TCR
decl_stmt|;
comment|// Transmit Counter Register
name|AT91_REG
name|MCI_RNPR
decl_stmt|;
comment|// Receive Next Pointer Register
name|AT91_REG
name|MCI_RNCR
decl_stmt|;
comment|// Receive Next Counter Register
name|AT91_REG
name|MCI_TNPR
decl_stmt|;
comment|// Transmit Next Pointer Register
name|AT91_REG
name|MCI_TNCR
decl_stmt|;
comment|// Transmit Next Counter Register
name|AT91_REG
name|MCI_PTCR
decl_stmt|;
comment|// PDC Transfer Control Register
name|AT91_REG
name|MCI_PTSR
decl_stmt|;
comment|// PDC Transfer Status Register
block|}
name|AT91S_MCI
operator|,
typedef|*
name|AT91PS_MCI
typedef|;
end_typedef

begin_comment
comment|// -------- MCI_CR : (MCI Offset: 0x0) MCI Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MCIEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MCI) Multimedia Interface Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MCIDIS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (MCI) Multimedia Interface Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PWSEN
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (MCI) Power Save Mode Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PWSDIS
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (MCI) Power Save Mode Disable
end_comment

begin_comment
comment|// -------- MCI_MR : (MCI Offset: 0x4) MCI Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_CLKDIV
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MCI) Clock Divider
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PWSDIV
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (MCI) Power Saving Divider
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PDCPADV
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (MCI) PDC Padding Value
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PDCMODE
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (MCI) PDC Oriented Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_BLKLEN
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (MCI) Data Block Length
end_comment

begin_comment
comment|// -------- MCI_DTOR : (MCI Offset: 0x8) MCI Data Timeout Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOCYC
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MCI) Data Timeout Cycle Number
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL
value|((unsigned int) 0x7<<  4)
end_define

begin_comment
comment|// (MCI) Data Timeout Multiplier
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_1
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 1
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_16
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 16
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_128
value|((unsigned int) 0x2<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 128
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_256
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 256
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_1024
value|((unsigned int) 0x4<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 1024
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_4096
value|((unsigned int) 0x5<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 4096
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_65536
value|((unsigned int) 0x6<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 65536
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOMUL_1048576
value|((unsigned int) 0x7<<  4)
end_define

begin_comment
comment|// (MCI) DTOCYC x 1048576
end_comment

begin_comment
comment|// -------- MCI_SDCR : (MCI Offset: 0xc) MCI SD Card Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SCDSEL
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MCI) SD Card Selector
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SCDBUS
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (MCI) SD Card Bus Width
end_comment

begin_comment
comment|// -------- MCI_CMDR : (MCI Offset: 0x14) MCI Command Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_CMDNB
value|((unsigned int) 0x1F<<  0)
end_define

begin_comment
comment|// (MCI) Command Number
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RSPTYP
value|((unsigned int) 0x3<<  6)
end_define

begin_comment
comment|// (MCI) Response Type
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RSPTYP_NO
value|((unsigned int) 0x0<<  6)
end_define

begin_comment
comment|// (MCI) No response
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RSPTYP_48
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (MCI) 48-bit response
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RSPTYP_136
value|((unsigned int) 0x2<<  6)
end_define

begin_comment
comment|// (MCI) 136-bit response
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (MCI) Special CMD
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD_NONE
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (MCI) Not a special CMD
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD_INIT
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (MCI) Initialization CMD
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD_SYNC
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (MCI) Synchronized CMD
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD_IT_CMD
value|((unsigned int) 0x4<<  8)
end_define

begin_comment
comment|// (MCI) Interrupt command
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SPCMD_IT_REP
value|((unsigned int) 0x5<<  8)
end_define

begin_comment
comment|// (MCI) Interrupt response
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_OPDCMD
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (MCI) Open Drain Command
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MAXLAT
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (MCI) Maximum Latency for Command to respond
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRCMD
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (MCI) Transfer CMD
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRCMD_NO
value|((unsigned int) 0x0<< 16)
end_define

begin_comment
comment|// (MCI) No transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRCMD_START
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (MCI) Start transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRCMD_STOP
value|((unsigned int) 0x2<< 16)
end_define

begin_comment
comment|// (MCI) Stop transfer
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRDIR
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (MCI) Transfer Direction
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRTYP
value|((unsigned int) 0x3<< 19)
end_define

begin_comment
comment|// (MCI) Transfer Type
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRTYP_BLOCK
value|((unsigned int) 0x0<< 19)
end_define

begin_comment
comment|// (MCI) Block Transfer type
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRTYP_MULTIPLE
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (MCI) Multiple Block transfer type
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TRTYP_STREAM
value|((unsigned int) 0x2<< 19)
end_define

begin_comment
comment|// (MCI) Stream transfer type
end_comment

begin_comment
comment|// -------- MCI_SR : (MCI Offset: 0x40) MCI Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_CMDRDY
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (MCI) Command Ready flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RXRDY
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (MCI) RX Ready flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TXRDY
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (MCI) TX Ready flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_BLKE
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (MCI) Data Block Transfer Ended flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTIP
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (MCI) Data Transfer in Progress flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_NOTBUSY
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (MCI) Data Line Not Busy flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_ENDRX
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (MCI) End of RX Buffer flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_ENDTX
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (MCI) End of TX Buffer flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RXBUFF
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (MCI) RX Buffer Full flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TXBUFE
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (MCI) TX Buffer Empty flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RINDE
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (MCI) Response Index Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RDIRE
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (MCI) Response Direction Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RCRCE
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (MCI) Response CRC Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RENDE
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (MCI) Response End Bit Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RTOE
value|((unsigned int) 0x1<< 20)
end_define

begin_comment
comment|// (MCI) Response Time-out Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DCRCE
value|((unsigned int) 0x1<< 21)
end_define

begin_comment
comment|// (MCI) data CRC Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOE
value|((unsigned int) 0x1<< 22)
end_define

begin_comment
comment|// (MCI) Data timeout Error flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_OVRE
value|((unsigned int) 0x1<< 30)
end_define

begin_comment
comment|// (MCI) Overrun flag
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_UNRE
value|((unsigned int) 0x1<< 31)
end_define

begin_comment
comment|// (MCI) Underrun flag
end_comment

begin_comment
comment|// -------- MCI_IER : (MCI Offset: 0x44) MCI Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- MCI_IDR : (MCI Offset: 0x48) MCI Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- MCI_IMR : (MCI Offset: 0x4c) MCI Interrupt Mask Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR USB Device Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_UDP
block|{
name|AT91_REG
name|UDP_NUM
decl_stmt|;
comment|// Frame Number Register
name|AT91_REG
name|UDP_GLBSTATE
decl_stmt|;
comment|// Global State Register
name|AT91_REG
name|UDP_FADDR
decl_stmt|;
comment|// Function Address Register
name|AT91_REG
name|Reserved0
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|UDP_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|UDP_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|UDP_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|UDP_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|UDP_ICR
decl_stmt|;
comment|// Interrupt Clear Register
name|AT91_REG
name|Reserved1
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|UDP_RSTEP
decl_stmt|;
comment|// Reset Endpoint Register
name|AT91_REG
name|Reserved2
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|UDP_CSR
index|[
literal|8
index|]
decl_stmt|;
comment|// Endpoint Control and Status Register
name|AT91_REG
name|UDP_FDR
index|[
literal|8
index|]
decl_stmt|;
comment|// Endpoint FIFO Data Register
block|}
name|AT91S_UDP
operator|,
typedef|*
name|AT91PS_UDP
typedef|;
end_typedef

begin_comment
comment|// -------- UDP_FRM_NUM : (UDP Offset: 0x0) USB Frame Number Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FRM_NUM
value|((unsigned int) 0x7FF<<  0)
end_define

begin_comment
comment|// (UDP) Frame Number as Defined in the Packet Field Formats
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FRM_ERR
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (UDP) Frame Error
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FRM_OK
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (UDP) Frame OK
end_comment

begin_comment
comment|// -------- UDP_GLB_STATE : (UDP Offset: 0x4) USB Global State Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FADDEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (UDP) Function Address Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_CONFG
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (UDP) Configured
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RMWUPE
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (UDP) Remote Wake Up Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RSMINPR
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (UDP) A Resume Has Been Sent to the Host
end_comment

begin_comment
comment|// -------- UDP_FADDR : (UDP Offset: 0x8) USB Function Address Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FADD
value|((unsigned int) 0xFF<<  0)
end_define

begin_comment
comment|// (UDP) Function Address Value
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FEN
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (UDP) Function Enable
end_comment

begin_comment
comment|// -------- UDP_IER : (UDP Offset: 0x10) USB Interrupt Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT0
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (UDP) Endpoint 0 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT1
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (UDP) Endpoint 0 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT2
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (UDP) Endpoint 2 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT3
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (UDP) Endpoint 3 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT4
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (UDP) Endpoint 4 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT5
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (UDP) Endpoint 5 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT6
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (UDP) Endpoint 6 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPINT7
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (UDP) Endpoint 7 Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RXSUSP
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (UDP) USB Suspend Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RXRSM
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (UDP) USB Resume Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EXTRSM
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (UDP) USB External Resume Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_SOFINT
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (UDP) USB Start Of frame Interrupt
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_WAKEUP
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (UDP) USB Resume Interrupt
end_comment

begin_comment
comment|// -------- UDP_IDR : (UDP Offset: 0x14) USB Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- UDP_IMR : (UDP Offset: 0x18) USB Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- UDP_ISR : (UDP Offset: 0x1c) USB Interrupt Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_ENDBUSRES
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (UDP) USB End Of Bus Reset Interrupt
end_comment

begin_comment
comment|// -------- UDP_ICR : (UDP Offset: 0x20) USB Interrupt Clear Register --------
end_comment

begin_comment
comment|// -------- UDP_RST_EP : (UDP Offset: 0x28) USB Reset Endpoint Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP0
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 0
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP1
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 1
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP2
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 2
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP3
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 3
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP4
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 4
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP5
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 5
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP6
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 6
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EP7
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (UDP) Reset Endpoint 7
end_comment

begin_comment
comment|// -------- UDP_CSR : (UDP Offset: 0x30) USB Endpoint Control and Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_TXCOMP
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (UDP) Generates an IN packet with data previously written in the DPR
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RX_DATA_BK0
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (UDP) Receive Data Bank 0
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RXSETUP
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (UDP) Sends STALL to the Host (Control endpoints)
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_ISOERROR
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (UDP) Isochronous error (Isochronous endpoints)
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_TXPKTRDY
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (UDP) Transmit Packet Ready
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FORCESTALL
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (UDP) Force Stall (used by Control, Bulk and Isochronous endpoints).
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RX_DATA_BK1
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (UDP) Receive Data Bank 1 (only used by endpoints with ping-pong attributes).
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_DIR
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (UDP) Transfer Direction
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (UDP) Endpoint type
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_CTRL
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (UDP) Control
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_ISO_OUT
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (UDP) Isochronous OUT
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_BULK_OUT
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (UDP) Bulk OUT
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_INT_OUT
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (UDP) Interrupt OUT
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_ISO_IN
value|((unsigned int) 0x5<<  8)
end_define

begin_comment
comment|// (UDP) Isochronous IN
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_BULK_IN
value|((unsigned int) 0x6<<  8)
end_define

begin_comment
comment|// (UDP) Bulk IN
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPTYPE_INT_IN
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (UDP) Interrupt IN
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_DTGLE
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (UDP) Data Toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_EPEDS
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (UDP) Endpoint Enable Disable
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RXBYTECNT
value|((unsigned int) 0x7FF<< 16)
end_define

begin_comment
comment|// (UDP) Number Of Bytes Available in the FIFO
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Timer Counter Channel Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_TC
block|{
name|AT91_REG
name|TC_CCR
decl_stmt|;
comment|// Channel Control Register
name|AT91_REG
name|TC_CMR
decl_stmt|;
comment|// Channel Mode Register
name|AT91_REG
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|TC_CV
decl_stmt|;
comment|// Counter Value
name|AT91_REG
name|TC_RA
decl_stmt|;
comment|// Register A
name|AT91_REG
name|TC_RB
decl_stmt|;
comment|// Register B
name|AT91_REG
name|TC_RC
decl_stmt|;
comment|// Register C
name|AT91_REG
name|TC_SR
decl_stmt|;
comment|// Status Register
name|AT91_REG
name|TC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|TC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|TC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
block|}
name|AT91S_TC
operator|,
typedef|*
name|AT91PS_TC
typedef|;
end_typedef

begin_comment
comment|// -------- TC_CCR : (TC Offset: 0x0) TC Channel Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CLKEN
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TC) Counter Clock Enable Command
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CLKDIS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (TC) Counter Clock Disable Command
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_SWTRG
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TC) Software Trigger Command
end_comment

begin_comment
comment|// -------- TC_CMR : (TC Offset: 0x4) TC Channel Mode Register: Capture Mode / Waveform Mode --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPCSTOP
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (TC) Counter Clock Stopped with RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPCDIS
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (TC) Counter Clock Disable with RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVTEDG
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (TC) External Event Edge Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVTEDG_NONE
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (TC) Edge: None
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVTEDG_RISING
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (TC) Edge: rising edge
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVTEDG_FALLING
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (TC) Edge: falling edge
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVTEDG_BOTH
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (TC) Edge: each edge
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVT
value|((unsigned int) 0x3<< 10)
end_define

begin_comment
comment|// (TC) External Event  Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVT_NONE
value|((unsigned int) 0x0<< 10)
end_define

begin_comment
comment|// (TC) Signal selected as external event: TIOB TIOB direction: input
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVT_RISING
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (TC) Signal selected as external event: XC0 TIOB direction: output
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVT_FALLING
value|((unsigned int) 0x2<< 10)
end_define

begin_comment
comment|// (TC) Signal selected as external event: XC1 TIOB direction: output
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_EEVT_BOTH
value|((unsigned int) 0x3<< 10)
end_define

begin_comment
comment|// (TC) Signal selected as external event: XC2 TIOB direction: output
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ENETRG
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (TC) External Event Trigger enable
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVESEL
value|((unsigned int) 0x3<< 13)
end_define

begin_comment
comment|// (TC) Waveform  Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVESEL_UP
value|((unsigned int) 0x0<< 13)
end_define

begin_comment
comment|// (TC) UP mode without atomatic trigger on RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVESEL_UP_AUTO
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (TC) UP mode with automatic trigger on RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVESEL_UPDOWN
value|((unsigned int) 0x2<< 13)
end_define

begin_comment
comment|// (TC) UPDOWN mode without automatic trigger on RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVESEL_UPDOWN_AUTO
value|((unsigned int) 0x3<< 13)
end_define

begin_comment
comment|// (TC) UPDOWN mode with automatic trigger on RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPCTRG
value|((unsigned int) 0x1<< 14)
end_define

begin_comment
comment|// (TC) RC Compare Trigger Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_WAVE
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (TC)
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPA
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (TC) RA Compare Effect on TIOA
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPA_NONE
value|((unsigned int) 0x0<< 16)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPA_SET
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPA_CLEAR
value|((unsigned int) 0x2<< 16)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPA_TOGGLE
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPC
value|((unsigned int) 0x3<< 18)
end_define

begin_comment
comment|// (TC) RC Compare Effect on TIOA
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPC_NONE
value|((unsigned int) 0x0<< 18)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPC_SET
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPC_CLEAR
value|((unsigned int) 0x2<< 18)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ACPC_TOGGLE
value|((unsigned int) 0x3<< 18)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_AEEVT
value|((unsigned int) 0x3<< 20)
end_define

begin_comment
comment|// (TC) External Event Effect on TIOA
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_AEEVT_NONE
value|((unsigned int) 0x0<< 20)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_AEEVT_SET
value|((unsigned int) 0x1<< 20)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_AEEVT_CLEAR
value|((unsigned int) 0x2<< 20)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_AEEVT_TOGGLE
value|((unsigned int) 0x3<< 20)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ASWTRG
value|((unsigned int) 0x3<< 22)
end_define

begin_comment
comment|// (TC) Software Trigger Effect on TIOA
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ASWTRG_NONE
value|((unsigned int) 0x0<< 22)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ASWTRG_SET
value|((unsigned int) 0x1<< 22)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ASWTRG_CLEAR
value|((unsigned int) 0x2<< 22)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ASWTRG_TOGGLE
value|((unsigned int) 0x3<< 22)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPB
value|((unsigned int) 0x3<< 24)
end_define

begin_comment
comment|// (TC) RB Compare Effect on TIOB
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPB_NONE
value|((unsigned int) 0x0<< 24)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPB_SET
value|((unsigned int) 0x1<< 24)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPB_CLEAR
value|((unsigned int) 0x2<< 24)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPB_TOGGLE
value|((unsigned int) 0x3<< 24)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPC
value|((unsigned int) 0x3<< 26)
end_define

begin_comment
comment|// (TC) RC Compare Effect on TIOB
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPC_NONE
value|((unsigned int) 0x0<< 26)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPC_SET
value|((unsigned int) 0x1<< 26)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPC_CLEAR
value|((unsigned int) 0x2<< 26)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BCPC_TOGGLE
value|((unsigned int) 0x3<< 26)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BEEVT
value|((unsigned int) 0x3<< 28)
end_define

begin_comment
comment|// (TC) External Event Effect on TIOB
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BEEVT_NONE
value|((unsigned int) 0x0<< 28)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BEEVT_SET
value|((unsigned int) 0x1<< 28)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BEEVT_CLEAR
value|((unsigned int) 0x2<< 28)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BEEVT_TOGGLE
value|((unsigned int) 0x3<< 28)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BSWTRG
value|((unsigned int) 0x3<< 30)
end_define

begin_comment
comment|// (TC) Software Trigger Effect on TIOB
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BSWTRG_NONE
value|((unsigned int) 0x0<< 30)
end_define

begin_comment
comment|// (TC) Effect: none
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BSWTRG_SET
value|((unsigned int) 0x1<< 30)
end_define

begin_comment
comment|// (TC) Effect: set
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BSWTRG_CLEAR
value|((unsigned int) 0x2<< 30)
end_define

begin_comment
comment|// (TC) Effect: clear
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_BSWTRG_TOGGLE
value|((unsigned int) 0x3<< 30)
end_define

begin_comment
comment|// (TC) Effect: toggle
end_comment

begin_comment
comment|// -------- TC_SR : (TC Offset: 0x20) TC Channel Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_COVFS
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TC) Counter Overflow
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_LOVRS
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (TC) Load Overrun
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPAS
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TC) RA Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPBS
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (TC) RB Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_CPCS
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (TC) RC Compare
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_LDRAS
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (TC) RA Loading
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_LDRBS
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (TC) RB Loading
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ETRCS
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (TC) External Trigger
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_ETRGS
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (TC) Clock Enabling
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_MTIOA
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (TC) TIOA Mirror
end_comment

begin_define
define|#
directive|define
name|AT91C_TC_MTIOB
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (TC) TIOA Mirror
end_comment

begin_comment
comment|// -------- TC_IER : (TC Offset: 0x24) TC Channel Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- TC_IDR : (TC Offset: 0x28) TC Channel Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- TC_IMR : (TC Offset: 0x2c) TC Channel Interrupt Mask Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Timer Counter Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_TCB
block|{
name|AT91S_TC
name|TCB_TC0
decl_stmt|;
comment|// TC Channel 0
name|AT91_REG
name|Reserved0
index|[
literal|4
index|]
decl_stmt|;
comment|//
name|AT91S_TC
name|TCB_TC1
decl_stmt|;
comment|// TC Channel 1
name|AT91_REG
name|Reserved1
index|[
literal|4
index|]
decl_stmt|;
comment|//
name|AT91S_TC
name|TCB_TC2
decl_stmt|;
comment|// TC Channel 2
name|AT91_REG
name|Reserved2
index|[
literal|4
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|TCB_BCR
decl_stmt|;
comment|// TC Block Control Register
name|AT91_REG
name|TCB_BMR
decl_stmt|;
comment|// TC Block Mode Register
block|}
name|AT91S_TCB
operator|,
typedef|*
name|AT91PS_TCB
typedef|;
end_typedef

begin_comment
comment|// -------- TCB_BCR : (TCB Offset: 0xc0) TC Block Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_SYNC
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TCB) Synchro Command
end_comment

begin_comment
comment|// -------- TCB_BMR : (TCB Offset: 0xc4) TC Block Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC0XC0S
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (TCB) External Clock Signal 0 Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC0XC0S_TCLK0
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (TCB) TCLK0 connected to XC0
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC0XC0S_NONE
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (TCB) None signal connected to XC0
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC0XC0S_TIOA1
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (TCB) TIOA1 connected to XC0
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC0XC0S_TIOA2
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (TCB) TIOA2 connected to XC0
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC1XC1S
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TCB) External Clock Signal 1 Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC1XC1S_TCLK1
value|((unsigned int) 0x0<<  2)
end_define

begin_comment
comment|// (TCB) TCLK1 connected to XC1
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC1XC1S_NONE
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (TCB) None signal connected to XC1
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC1XC1S_TIOA0
value|((unsigned int) 0x2<<  2)
end_define

begin_comment
comment|// (TCB) TIOA0 connected to XC1
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC1XC1S_TIOA2
value|((unsigned int) 0x3<<  2)
end_define

begin_comment
comment|// (TCB) TIOA2 connected to XC1
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC2XC2S
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (TCB) External Clock Signal 2 Selection
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC2XC2S_TCLK2
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (TCB) TCLK2 connected to XC2
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC2XC2S_NONE
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (TCB) None signal connected to XC2
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC2XC2S_TIOA0
value|((unsigned int) 0x2<<  4)
end_define

begin_comment
comment|// (TCB) TIOA0 connected to XC2
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB_TC2XC2S_TIOA2
value|((unsigned int) 0x3<<  4)
end_define

begin_comment
comment|// (TCB) TIOA2 connected to XC2
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR USB Host Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_UHP
block|{
name|AT91_REG
name|UHP_HcRevision
decl_stmt|;
comment|// Revision
name|AT91_REG
name|UHP_HcControl
decl_stmt|;
comment|// Operating modes for the Host Controller
name|AT91_REG
name|UHP_HcCommandStatus
decl_stmt|;
comment|// Command& status Register
name|AT91_REG
name|UHP_HcInterruptStatus
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|UHP_HcInterruptEnable
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|UHP_HcInterruptDisable
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|UHP_HcHCCA
decl_stmt|;
comment|// Pointer to the Host Controller Communication Area
name|AT91_REG
name|UHP_HcPeriodCurrentED
decl_stmt|;
comment|// Current Isochronous or Interrupt Endpoint Descriptor
name|AT91_REG
name|UHP_HcControlHeadED
decl_stmt|;
comment|// First Endpoint Descriptor of the Control list
name|AT91_REG
name|UHP_HcControlCurrentED
decl_stmt|;
comment|// Endpoint Control and Status Register
name|AT91_REG
name|UHP_HcBulkHeadED
decl_stmt|;
comment|// First endpoint register of the Bulk list
name|AT91_REG
name|UHP_HcBulkCurrentED
decl_stmt|;
comment|// Current endpoint of the Bulk list
name|AT91_REG
name|UHP_HcBulkDoneHead
decl_stmt|;
comment|// Last completed transfer descriptor
name|AT91_REG
name|UHP_HcFmInterval
decl_stmt|;
comment|// Bit time between 2 consecutive SOFs
name|AT91_REG
name|UHP_HcFmRemaining
decl_stmt|;
comment|// Bit time remaining in the current Frame
name|AT91_REG
name|UHP_HcFmNumber
decl_stmt|;
comment|// Frame number
name|AT91_REG
name|UHP_HcPeriodicStart
decl_stmt|;
comment|// Periodic Start
name|AT91_REG
name|UHP_HcLSThreshold
decl_stmt|;
comment|// LS Threshold
name|AT91_REG
name|UHP_HcRhDescriptorA
decl_stmt|;
comment|// Root Hub characteristics A
name|AT91_REG
name|UHP_HcRhDescriptorB
decl_stmt|;
comment|// Root Hub characteristics B
name|AT91_REG
name|UHP_HcRhStatus
decl_stmt|;
comment|// Root Hub Status register
name|AT91_REG
name|UHP_HcRhPortStatus
index|[
literal|2
index|]
decl_stmt|;
comment|// Root Hub Port Status Register
block|}
name|AT91S_UHP
operator|,
typedef|*
name|AT91PS_UHP
typedef|;
end_typedef

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Ethernet MAC
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_EMAC
block|{
name|AT91_REG
name|EMAC_CTL
decl_stmt|;
comment|// Network Control Register
name|AT91_REG
name|EMAC_CFG
decl_stmt|;
comment|// Network Configuration Register
name|AT91_REG
name|EMAC_SR
decl_stmt|;
comment|// Network Status Register
name|AT91_REG
name|EMAC_TAR
decl_stmt|;
comment|// Transmit Address Register
name|AT91_REG
name|EMAC_TCR
decl_stmt|;
comment|// Transmit Control Register
name|AT91_REG
name|EMAC_TSR
decl_stmt|;
comment|// Transmit Status Register
name|AT91_REG
name|EMAC_RBQP
decl_stmt|;
comment|// Receive Buffer Queue Pointer
name|AT91_REG
name|Reserved0
index|[
literal|1
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EMAC_RSR
decl_stmt|;
comment|// Receive Status Register
name|AT91_REG
name|EMAC_ISR
decl_stmt|;
comment|// Interrupt Status Register
name|AT91_REG
name|EMAC_IER
decl_stmt|;
comment|// Interrupt Enable Register
name|AT91_REG
name|EMAC_IDR
decl_stmt|;
comment|// Interrupt Disable Register
name|AT91_REG
name|EMAC_IMR
decl_stmt|;
comment|// Interrupt Mask Register
name|AT91_REG
name|EMAC_MAN
decl_stmt|;
comment|// PHY Maintenance Register
name|AT91_REG
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EMAC_FRA
decl_stmt|;
comment|// Frames Transmitted OK Register
name|AT91_REG
name|EMAC_SCOL
decl_stmt|;
comment|// Single Collision Frame Register
name|AT91_REG
name|EMAC_MCOL
decl_stmt|;
comment|// Multiple Collision Frame Register
name|AT91_REG
name|EMAC_OK
decl_stmt|;
comment|// Frames Received OK Register
name|AT91_REG
name|EMAC_SEQE
decl_stmt|;
comment|// Frame Check Sequence Error Register
name|AT91_REG
name|EMAC_ALE
decl_stmt|;
comment|// Alignment Error Register
name|AT91_REG
name|EMAC_DTE
decl_stmt|;
comment|// Deferred Transmission Frame Register
name|AT91_REG
name|EMAC_LCOL
decl_stmt|;
comment|// Late Collision Register
name|AT91_REG
name|EMAC_ECOL
decl_stmt|;
comment|// Excessive Collision Register
name|AT91_REG
name|EMAC_CSE
decl_stmt|;
comment|// Carrier Sense Error Register
name|AT91_REG
name|EMAC_TUE
decl_stmt|;
comment|// Transmit Underrun Error Register
name|AT91_REG
name|EMAC_CDE
decl_stmt|;
comment|// Code Error Register
name|AT91_REG
name|EMAC_ELR
decl_stmt|;
comment|// Excessive Length Error Register
name|AT91_REG
name|EMAC_RJB
decl_stmt|;
comment|// Receive Jabber Register
name|AT91_REG
name|EMAC_USF
decl_stmt|;
comment|// Undersize Frame Register
name|AT91_REG
name|EMAC_SQEE
decl_stmt|;
comment|// SQE Test Error Register
name|AT91_REG
name|EMAC_DRFC
decl_stmt|;
comment|// Discarded RX Frame Register
name|AT91_REG
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|//
name|AT91_REG
name|EMAC_HSH
decl_stmt|;
comment|// Hash Address High[63:32]
name|AT91_REG
name|EMAC_HSL
decl_stmt|;
comment|// Hash Address Low[31:0]
name|AT91_REG
name|EMAC_SA1L
decl_stmt|;
comment|// Specific Address 1 Low, First 4 bytes
name|AT91_REG
name|EMAC_SA1H
decl_stmt|;
comment|// Specific Address 1 High, Last 2 bytes
name|AT91_REG
name|EMAC_SA2L
decl_stmt|;
comment|// Specific Address 2 Low, First 4 bytes
name|AT91_REG
name|EMAC_SA2H
decl_stmt|;
comment|// Specific Address 2 High, Last 2 bytes
name|AT91_REG
name|EMAC_SA3L
decl_stmt|;
comment|// Specific Address 3 Low, First 4 bytes
name|AT91_REG
name|EMAC_SA3H
decl_stmt|;
comment|// Specific Address 3 High, Last 2 bytes
name|AT91_REG
name|EMAC_SA4L
decl_stmt|;
comment|// Specific Address 4 Low, First 4 bytes
name|AT91_REG
name|EMAC_SA4H
decl_stmt|;
comment|// Specific Address 4 High, Last 2 bytesr
block|}
name|AT91S_EMAC
operator|,
typedef|*
name|AT91PS_EMAC
typedef|;
end_typedef

begin_comment
comment|// -------- EMAC_CTL : (EMAC Offset: 0x0)  --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LB
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EMAC) Loopback. Optional. When set, loopback signal is at high level.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LBL
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC) Loopback local.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RE
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (EMAC) Receive enable.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TE
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (EMAC) Transmit enable.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_MPE
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EMAC) Management port enable.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CSR
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (EMAC) Clear statistics registers.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_ISR
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (EMAC) Increment statistics registers.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_WES
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (EMAC) Write enable for statistics registers.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_BP
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (EMAC) Back pressure.
end_comment

begin_comment
comment|// -------- EMAC_CFG : (EMAC Offset: 0x4) Network Configuration Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SPD
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EMAC) Speed.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_FD
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC) Full duplex.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_BR
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (EMAC) Bit rate.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CAF
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EMAC) Copy all frames.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_NBC
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (EMAC) No broadcast.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_MTI
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (EMAC) Multicast hash enable
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_UNI
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (EMAC) Unicast hash enable.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_BIG
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (EMAC) Receive 1522 bytes.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_EAE
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (EMAC) External address match enable.
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CLK
value|((unsigned int) 0x3<< 10)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CLK_HCLK_8
value|((unsigned int) 0x0<< 10)
end_define

begin_comment
comment|// (EMAC) HCLK divided by 8
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CLK_HCLK_16
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (EMAC) HCLK divided by 16
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CLK_HCLK_32
value|((unsigned int) 0x2<< 10)
end_define

begin_comment
comment|// (EMAC) HCLK divided by 32
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CLK_HCLK_64
value|((unsigned int) 0x3<< 10)
end_define

begin_comment
comment|// (EMAC) HCLK divided by 64
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RTY
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RMII
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_SR : (EMAC Offset: 0x8) Network Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_MDIO
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_IDLE
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_TCR : (EMAC Offset: 0x10) Transmit Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LEN
value|((unsigned int) 0x7FF<<  0)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_NCRC
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_TSR : (EMAC Offset: 0x14) Transmit Control Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_OVR
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_COL
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RLE
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TXIDLE
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_BNQ
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_COMP
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_UND
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_RSR : (EMAC Offset: 0x20) Receive Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_BNA
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_REC
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_ISR : (EMAC Offset: 0x24) Interrupt Status Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_DONE
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RCOM
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RBNA
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TOVR
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TUND
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RTRY
value|((unsigned int) 0x1<<  5)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TBRE
value|((unsigned int) 0x1<<  6)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TCOM
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TIDLE
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LINK
value|((unsigned int) 0x1<<  9)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_ROVR
value|((unsigned int) 0x1<< 10)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_HRESP
value|((unsigned int) 0x1<< 11)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// -------- EMAC_IER : (EMAC Offset: 0x28) Interrupt Enable Register --------
end_comment

begin_comment
comment|// -------- EMAC_IDR : (EMAC Offset: 0x2c) Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- EMAC_IMR : (EMAC Offset: 0x30) Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- EMAC_MAN : (EMAC Offset: 0x34) PHY Maintenance Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_DATA
value|((unsigned int) 0xFFFF<<  0)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CODE
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_REGA
value|((unsigned int) 0x1F<< 18)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_PHYA
value|((unsigned int) 0x1F<< 23)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RW
value|((unsigned int) 0x3<< 28)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_HIGH
value|((unsigned int) 0x1<< 30)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LOW
value|((unsigned int) 0x1<< 31)
end_define

begin_comment
comment|// (EMAC)
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR External Bus Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_EBI
block|{
name|AT91_REG
name|EBI_CSA
decl_stmt|;
comment|// Chip Select Assignment Register
name|AT91_REG
name|EBI_CFGR
decl_stmt|;
comment|// Configuration Register
block|}
name|AT91S_EBI
operator|,
typedef|*
name|AT91PS_EBI
typedef|;
end_typedef

begin_comment
comment|// -------- EBI_CSA : (EBI Offset: 0x0) Chip Select Assignment Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS0A
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EBI) Chip Select 0 Assignment
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS0A_SMC
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (EBI) Chip Select 0 is assigned to the Static Memory Controller.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS0A_BFC
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (EBI) Chip Select 0 is assigned to the Burst Flash Controller.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS1A
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EBI) Chip Select 1 Assignment
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS1A_SMC
value|((unsigned int) 0x0<<  1)
end_define

begin_comment
comment|// (EBI) Chip Select 1 is assigned to the Static Memory Controller.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS1A_SDRAMC
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EBI) Chip Select 1 is assigned to the SDRAM Controller.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS3A
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (EBI) Chip Select 3 Assignment
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS3A_SMC
value|((unsigned int) 0x0<<  3)
end_define

begin_comment
comment|// (EBI) Chip Select 3 is only assigned to the Static Memory Controller and NCS3 behaves as defined by the SMC2.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS3A_SMC_SmartMedia
value|((unsigned int) 0x1<<  3)
end_define

begin_comment
comment|// (EBI) Chip Select 3 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS4A
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EBI) Chip Select 4 Assignment
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS4A_SMC
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (EBI) Chip Select 4 is assigned to the Static Memory Controller and NCS4,NCS5 and NCS6 behave as defined by the SMC2.
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CS4A_SMC_CompactFlash
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (EBI) Chip Select 4 is assigned to the Static Memory Controller and the CompactFlash Logic is activated.
end_comment

begin_comment
comment|// -------- EBI_CFGR : (EBI Offset: 0x4) Configuration Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_DBPUC
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (EBI) Data Bus Pull-Up Configuration
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_EBSEN
value|((unsigned int) 0x1<<  1)
end_define

begin_comment
comment|// (EBI) Bus Sharing Enable
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Static Memory Controller 2 Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_SMC2
block|{
name|AT91_REG
name|SMC2_CSR
index|[
literal|8
index|]
decl_stmt|;
comment|// SMC2 Chip Select Register
block|}
name|AT91S_SMC2
operator|,
typedef|*
name|AT91PS_SMC2
typedef|;
end_typedef

begin_comment
comment|// -------- SMC2_CSR : (SMC2 Offset: 0x0) SMC2 Chip Select Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_NWS
value|((unsigned int) 0x7F<<  0)
end_define

begin_comment
comment|// (SMC2) Number of Wait States
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_WSEN
value|((unsigned int) 0x1<<  7)
end_define

begin_comment
comment|// (SMC2) Wait State Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_TDF
value|((unsigned int) 0xF<<  8)
end_define

begin_comment
comment|// (SMC2) Data Float Time
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_BAT
value|((unsigned int) 0x1<< 12)
end_define

begin_comment
comment|// (SMC2) Byte Access Type
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_DBW
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (SMC2) Data Bus Width
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_DBW_16
value|((unsigned int) 0x1<< 13)
end_define

begin_comment
comment|// (SMC2) 16-bit.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_DBW_8
value|((unsigned int) 0x2<< 13)
end_define

begin_comment
comment|// (SMC2) 8-bit.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_DRP
value|((unsigned int) 0x1<< 15)
end_define

begin_comment
comment|// (SMC2) Data Read Protocol
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_ACSS
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (SMC2) Address to Chip Select Setup
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_ACSS_STANDARD
value|((unsigned int) 0x0<< 16)
end_define

begin_comment
comment|// (SMC2) Standard, asserted at the beginning of the access and deasserted at the end.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_ACSS_1_CYCLE
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (SMC2) One cycle less at the beginning and the end of the access.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_ACSS_2_CYCLES
value|((unsigned int) 0x2<< 16)
end_define

begin_comment
comment|// (SMC2) Two cycles less at the beginning and the end of the access.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_ACSS_3_CYCLES
value|((unsigned int) 0x3<< 16)
end_define

begin_comment
comment|// (SMC2) Three cycles less at the beginning and the end of the access.
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_RWSETUP
value|((unsigned int) 0x7<< 24)
end_define

begin_comment
comment|// (SMC2) Read and Write Signal Setup Time
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_RWHOLD
value|((unsigned int) 0x7<< 29)
end_define

begin_comment
comment|// (SMC2) Read and Write Signal Hold Time
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR SDRAM Controller Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_SDRC
block|{
name|AT91_REG
name|SDRC_MR
decl_stmt|;
comment|// SDRAM Controller Mode Register
name|AT91_REG
name|SDRC_TR
decl_stmt|;
comment|// SDRAM Controller Refresh Timer Register
name|AT91_REG
name|SDRC_CR
decl_stmt|;
comment|// SDRAM Controller Configuration Register
name|AT91_REG
name|SDRC_SRR
decl_stmt|;
comment|// SDRAM Controller Self Refresh Register
name|AT91_REG
name|SDRC_LPR
decl_stmt|;
comment|// SDRAM Controller Low Power Register
name|AT91_REG
name|SDRC_IER
decl_stmt|;
comment|// SDRAM Controller Interrupt Enable Register
name|AT91_REG
name|SDRC_IDR
decl_stmt|;
comment|// SDRAM Controller Interrupt Disable Register
name|AT91_REG
name|SDRC_IMR
decl_stmt|;
comment|// SDRAM Controller Interrupt Mask Register
name|AT91_REG
name|SDRC_ISR
decl_stmt|;
comment|// SDRAM Controller Interrupt Mask Register
block|}
name|AT91S_SDRC
operator|,
typedef|*
name|AT91PS_SDRC
typedef|;
end_typedef

begin_comment
comment|// -------- SDRC_MR : (SDRC Offset: 0x0) SDRAM Controller Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE
value|((unsigned int) 0xF<<  0)
end_define

begin_comment
comment|// (SDRC) Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE_NORMAL_CMD
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (SDRC) Normal Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE_NOP_CMD
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (SDRC) NOP Command
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE_PRCGALL_CMD
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (SDRC) All Banks Precharge Command
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE_LMR_CMD
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (SDRC) Load Mode Register Command
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MODE_RFSH_CMD
value|((unsigned int) 0x4)
end_define

begin_comment
comment|// (SDRC) Refresh Command
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_DBW
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SDRC) Data Bus Width
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_DBW_32_BITS
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (SDRC) 32 Bits datas bus
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_DBW_16_BITS
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SDRC) 16 Bits datas bus
end_comment

begin_comment
comment|// -------- SDRC_TR : (SDRC Offset: 0x4) SDRC Refresh Timer Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_COUNT
value|((unsigned int) 0xFFF<<  0)
end_define

begin_comment
comment|// (SDRC) Refresh Counter
end_comment

begin_comment
comment|// -------- SDRC_CR : (SDRC Offset: 0x8) SDRAM Configuration Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NC
value|((unsigned int) 0x3<<  0)
end_define

begin_comment
comment|// (SDRC) Number of Column Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NC_8
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (SDRC) 8 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NC_9
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (SDRC) 9 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NC_10
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (SDRC) 10 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NC_11
value|((unsigned int) 0x3)
end_define

begin_comment
comment|// (SDRC) 11 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NR
value|((unsigned int) 0x3<<  2)
end_define

begin_comment
comment|// (SDRC) Number of Row Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NR_11
value|((unsigned int) 0x0<<  2)
end_define

begin_comment
comment|// (SDRC) 11 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NR_12
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (SDRC) 12 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NR_13
value|((unsigned int) 0x2<<  2)
end_define

begin_comment
comment|// (SDRC) 13 Bits
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NB
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SDRC) Number of Banks
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NB_2_BANKS
value|((unsigned int) 0x0<<  4)
end_define

begin_comment
comment|// (SDRC) 2 banks
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_NB_4_BANKS
value|((unsigned int) 0x1<<  4)
end_define

begin_comment
comment|// (SDRC) 4 banks
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_CAS
value|((unsigned int) 0x3<<  5)
end_define

begin_comment
comment|// (SDRC) CAS Latency
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_CAS_2
value|((unsigned int) 0x2<<  5)
end_define

begin_comment
comment|// (SDRC) 2 cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TWR
value|((unsigned int) 0xF<<  7)
end_define

begin_comment
comment|// (SDRC) Number of Write Recovery Time Cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TRC
value|((unsigned int) 0xF<< 11)
end_define

begin_comment
comment|// (SDRC) Number of RAS Cycle Time Cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TRP
value|((unsigned int) 0xF<< 15)
end_define

begin_comment
comment|// (SDRC) Number of RAS Precharge Time Cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TRCD
value|((unsigned int) 0xF<< 19)
end_define

begin_comment
comment|// (SDRC) Number of RAS to CAS Delay Cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TRAS
value|((unsigned int) 0xF<< 23)
end_define

begin_comment
comment|// (SDRC) Number of RAS Active Time Cycles
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TXSR
value|((unsigned int) 0xF<< 27)
end_define

begin_comment
comment|// (SDRC) Number of Command Recovery Time Cycles
end_comment

begin_comment
comment|// -------- SDRC_SRR : (SDRC Offset: 0xc) SDRAM Controller Self-refresh Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_SRCB
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SDRC) Self-refresh Command Bit
end_comment

begin_comment
comment|// -------- SDRC_LPR : (SDRC Offset: 0x10) SDRAM Controller Low-power Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_LPCB
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SDRC) Low-power Command Bit
end_comment

begin_comment
comment|// -------- SDRC_IER : (SDRC Offset: 0x14) SDRAM Controller Interrupt Enable Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_RES
value|((unsigned int) 0x1<<  0)
end_define

begin_comment
comment|// (SDRC) Refresh Error Status
end_comment

begin_comment
comment|// -------- SDRC_IDR : (SDRC Offset: 0x18) SDRAM Controller Interrupt Disable Register --------
end_comment

begin_comment
comment|// -------- SDRC_IMR : (SDRC Offset: 0x1c) SDRAM Controller Interrupt Mask Register --------
end_comment

begin_comment
comment|// -------- SDRC_ISR : (SDRC Offset: 0x20) SDRAM Controller Interrupt Status Register --------
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//              SOFTWARE API DEFINITION  FOR Burst Flash Controller Interface
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_BFC
block|{
name|AT91_REG
name|BFC_MR
decl_stmt|;
comment|// BFC Mode Register
block|}
name|AT91S_BFC
operator|,
typedef|*
name|AT91PS_BFC
typedef|;
end_typedef

begin_comment
comment|// -------- BFC_MR : (BFC Offset: 0x0) BFC Mode Register --------
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCOM
value|((unsigned int) 0x3<<  0)
end_define

begin_comment
comment|// (BFC) Burst Flash Controller Operating Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCOM_DISABLED
value|((unsigned int) 0x0)
end_define

begin_comment
comment|// (BFC) NPCS0 is driven by the SMC or remains high.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCOM_ASYNC
value|((unsigned int) 0x1)
end_define

begin_comment
comment|// (BFC) Asynchronous
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCOM_BURST_READ
value|((unsigned int) 0x2)
end_define

begin_comment
comment|// (BFC) Burst Read
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCC
value|((unsigned int) 0x3<<  2)
end_define

begin_comment
comment|// (BFC) Burst Flash Controller Operating Mode
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCC_MCK
value|((unsigned int) 0x1<<  2)
end_define

begin_comment
comment|// (BFC) Master Clock.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCC_MCK_DIV_2
value|((unsigned int) 0x2<<  2)
end_define

begin_comment
comment|// (BFC) Master Clock divided by 2.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFCC_MCK_DIV_4
value|((unsigned int) 0x3<<  2)
end_define

begin_comment
comment|// (BFC) Master Clock divided by 4.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_AVL
value|((unsigned int) 0xF<<  4)
end_define

begin_comment
comment|// (BFC) Address Valid Latency
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (BFC) Page Size
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_NO_PAGE
value|((unsigned int) 0x0<<  8)
end_define

begin_comment
comment|// (BFC) No page handling.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_16
value|((unsigned int) 0x1<<  8)
end_define

begin_comment
comment|// (BFC) 16 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_32
value|((unsigned int) 0x2<<  8)
end_define

begin_comment
comment|// (BFC) 32 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_64
value|((unsigned int) 0x3<<  8)
end_define

begin_comment
comment|// (BFC) 64 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_128
value|((unsigned int) 0x4<<  8)
end_define

begin_comment
comment|// (BFC) 128 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_256
value|((unsigned int) 0x5<<  8)
end_define

begin_comment
comment|// (BFC) 256 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_512
value|((unsigned int) 0x6<<  8)
end_define

begin_comment
comment|// (BFC) 512 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_PAGES_1024
value|((unsigned int) 0x7<<  8)
end_define

begin_comment
comment|// (BFC) 1024 bytes page size.
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_OEL
value|((unsigned int) 0x3<< 12)
end_define

begin_comment
comment|// (BFC) Output Enable Latency
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BAAEN
value|((unsigned int) 0x1<< 16)
end_define

begin_comment
comment|// (BFC) Burst Address Advance Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_BFOEH
value|((unsigned int) 0x1<< 17)
end_define

begin_comment
comment|// (BFC) Burst Flash Output Enable Handling
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_MUXEN
value|((unsigned int) 0x1<< 18)
end_define

begin_comment
comment|// (BFC) Multiplexed Bus Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_RDYEN
value|((unsigned int) 0x1<< 19)
end_define

begin_comment
comment|// (BFC) Ready Enable Mode
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               REGISTER ADDRESS DEFINITION FOR AT91RM9200
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|// ========== Register definition for SYS peripheral ==========
end_comment

begin_comment
comment|// ========== Register definition for MC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PUER
value|((AT91_REG *) 	0xFFFFFF54)
end_define

begin_comment
comment|// (MC) MC Protection Unit Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_ASR
value|((AT91_REG *) 	0xFFFFFF04)
end_define

begin_comment
comment|// (MC) MC Abort Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PUP
value|((AT91_REG *) 	0xFFFFFF50)
end_define

begin_comment
comment|// (MC) MC Protection Unit Peripherals
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_PUIA
value|((AT91_REG *) 	0xFFFFFF10)
end_define

begin_comment
comment|// (MC) MC Protection Unit Area
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_AASR
value|((AT91_REG *) 	0xFFFFFF08)
end_define

begin_comment
comment|// (MC) MC Abort Address Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MC_RCR
value|((AT91_REG *) 	0xFFFFFF00)
end_define

begin_comment
comment|// (MC) MC Remap Control Register
end_comment

begin_comment
comment|// ========== Register definition for RTC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_IMR
value|((AT91_REG *) 	0xFFFFFE28)
end_define

begin_comment
comment|// (RTC) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_IER
value|((AT91_REG *) 	0xFFFFFE20)
end_define

begin_comment
comment|// (RTC) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_SR
value|((AT91_REG *) 	0xFFFFFE18)
end_define

begin_comment
comment|// (RTC) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMALR
value|((AT91_REG *) 	0xFFFFFE10)
end_define

begin_comment
comment|// (RTC) Time Alarm Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_TIMR
value|((AT91_REG *) 	0xFFFFFE08)
end_define

begin_comment
comment|// (RTC) Time Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CR
value|((AT91_REG *) 	0xFFFFFE00)
end_define

begin_comment
comment|// (RTC) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_VER
value|((AT91_REG *) 	0xFFFFFE2C)
end_define

begin_comment
comment|// (RTC) Valid Entry Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_IDR
value|((AT91_REG *) 	0xFFFFFE24)
end_define

begin_comment
comment|// (RTC) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_SCCR
value|((AT91_REG *) 	0xFFFFFE1C)
end_define

begin_comment
comment|// (RTC) Status Clear Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALALR
value|((AT91_REG *) 	0xFFFFFE14)
end_define

begin_comment
comment|// (RTC) Calendar Alarm Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_CALR
value|((AT91_REG *) 	0xFFFFFE0C)
end_define

begin_comment
comment|// (RTC) Calendar Register
end_comment

begin_define
define|#
directive|define
name|AT91C_RTC_MR
value|((AT91_REG *) 	0xFFFFFE04)
end_define

begin_comment
comment|// (RTC) Mode Register
end_comment

begin_comment
comment|// ========== Register definition for ST peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_CRTR
value|((AT91_REG *) 	0xFFFFFD24)
end_define

begin_comment
comment|// (ST) Current Real-time Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_IMR
value|((AT91_REG *) 	0xFFFFFD1C)
end_define

begin_comment
comment|// (ST) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_IER
value|((AT91_REG *) 	0xFFFFFD14)
end_define

begin_comment
comment|// (ST) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_RTMR
value|((AT91_REG *) 	0xFFFFFD0C)
end_define

begin_comment
comment|// (ST) Real-time Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_PIMR
value|((AT91_REG *) 	0xFFFFFD04)
end_define

begin_comment
comment|// (ST) Period Interval Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_RTAR
value|((AT91_REG *) 	0xFFFFFD20)
end_define

begin_comment
comment|// (ST) Real-time Alarm Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_IDR
value|((AT91_REG *) 	0xFFFFFD18)
end_define

begin_comment
comment|// (ST) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_SR
value|((AT91_REG *) 	0xFFFFFD10)
end_define

begin_comment
comment|// (ST) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_WDMR
value|((AT91_REG *) 	0xFFFFFD08)
end_define

begin_comment
comment|// (ST) Watchdog Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_ST_CR
value|((AT91_REG *) 	0xFFFFFD00)
end_define

begin_comment
comment|// (ST) Control Register
end_comment

begin_comment
comment|// ========== Register definition for PMC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_SCSR
value|((AT91_REG *) 	0xFFFFFC08)
end_define

begin_comment
comment|// (PMC) System Clock Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_SCER
value|((AT91_REG *) 	0xFFFFFC00)
end_define

begin_comment
comment|// (PMC) System Clock Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_IMR
value|((AT91_REG *) 	0xFFFFFC6C)
end_define

begin_comment
comment|// (PMC) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_IDR
value|((AT91_REG *) 	0xFFFFFC64)
end_define

begin_comment
comment|// (PMC) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCDR
value|((AT91_REG *) 	0xFFFFFC14)
end_define

begin_comment
comment|// (PMC) Peripheral Clock Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_SCDR
value|((AT91_REG *) 	0xFFFFFC04)
end_define

begin_comment
comment|// (PMC) System Clock Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_SR
value|((AT91_REG *) 	0xFFFFFC68)
end_define

begin_comment
comment|// (PMC) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_IER
value|((AT91_REG *) 	0xFFFFFC60)
end_define

begin_comment
comment|// (PMC) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_MCKR
value|((AT91_REG *) 	0xFFFFFC30)
end_define

begin_comment
comment|// (PMC) Master Clock Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCER
value|((AT91_REG *) 	0xFFFFFC10)
end_define

begin_comment
comment|// (PMC) Peripheral Clock Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCSR
value|((AT91_REG *) 	0xFFFFFC18)
end_define

begin_comment
comment|// (PMC) Peripheral Clock Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PMC_PCKR
value|((AT91_REG *) 	0xFFFFFC40)
end_define

begin_comment
comment|// (PMC) Programmable Clock Register
end_comment

begin_comment
comment|// ========== Register definition for CKGR peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_PLLBR
value|((AT91_REG *) 	0xFFFFFC2C)
end_define

begin_comment
comment|// (CKGR) PLL B Register
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MCFR
value|((AT91_REG *) 	0xFFFFFC24)
end_define

begin_comment
comment|// (CKGR) Main Clock  Frequency Register
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_PLLAR
value|((AT91_REG *) 	0xFFFFFC28)
end_define

begin_comment
comment|// (CKGR) PLL A Register
end_comment

begin_define
define|#
directive|define
name|AT91C_CKGR_MOR
value|((AT91_REG *) 	0xFFFFFC20)
end_define

begin_comment
comment|// (CKGR) Main Oscillator Register
end_comment

begin_comment
comment|// ========== Register definition for PIOD peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PDSR
value|((AT91_REG *) 	0xFFFFFA3C)
end_define

begin_comment
comment|// (PIOD) Pin Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_CODR
value|((AT91_REG *) 	0xFFFFFA34)
end_define

begin_comment
comment|// (PIOD) Clear Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_OWER
value|((AT91_REG *) 	0xFFFFFAA0)
end_define

begin_comment
comment|// (PIOD) Output Write Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_MDER
value|((AT91_REG *) 	0xFFFFFA50)
end_define

begin_comment
comment|// (PIOD) Multi-driver Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IMR
value|((AT91_REG *) 	0xFFFFFA48)
end_define

begin_comment
comment|// (PIOD) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IER
value|((AT91_REG *) 	0xFFFFFA40)
end_define

begin_comment
comment|// (PIOD) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_ODSR
value|((AT91_REG *) 	0xFFFFFA38)
end_define

begin_comment
comment|// (PIOD) Output Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_SODR
value|((AT91_REG *) 	0xFFFFFA30)
end_define

begin_comment
comment|// (PIOD) Set Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PER
value|((AT91_REG *) 	0xFFFFFA00)
end_define

begin_comment
comment|// (PIOD) PIO Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_OWDR
value|((AT91_REG *) 	0xFFFFFAA4)
end_define

begin_comment
comment|// (PIOD) Output Write Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PPUER
value|((AT91_REG *) 	0xFFFFFA64)
end_define

begin_comment
comment|// (PIOD) Pull-up Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_MDDR
value|((AT91_REG *) 	0xFFFFFA54)
end_define

begin_comment
comment|// (PIOD) Multi-driver Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_ISR
value|((AT91_REG *) 	0xFFFFFA4C)
end_define

begin_comment
comment|// (PIOD) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IDR
value|((AT91_REG *) 	0xFFFFFA44)
end_define

begin_comment
comment|// (PIOD) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PDR
value|((AT91_REG *) 	0xFFFFFA04)
end_define

begin_comment
comment|// (PIOD) PIO Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_ODR
value|((AT91_REG *) 	0xFFFFFA14)
end_define

begin_comment
comment|// (PIOD) Output Disable Registerr
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_OWSR
value|((AT91_REG *) 	0xFFFFFAA8)
end_define

begin_comment
comment|// (PIOD) Output Write Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_ABSR
value|((AT91_REG *) 	0xFFFFFA78)
end_define

begin_comment
comment|// (PIOD) AB Select Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_ASR
value|((AT91_REG *) 	0xFFFFFA70)
end_define

begin_comment
comment|// (PIOD) Select A Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PPUSR
value|((AT91_REG *) 	0xFFFFFA68)
end_define

begin_comment
comment|// (PIOD) Pad Pull-up Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PPUDR
value|((AT91_REG *) 	0xFFFFFA60)
end_define

begin_comment
comment|// (PIOD) Pull-up Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_MDSR
value|((AT91_REG *) 	0xFFFFFA58)
end_define

begin_comment
comment|// (PIOD) Multi-driver Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_PSR
value|((AT91_REG *) 	0xFFFFFA08)
end_define

begin_comment
comment|// (PIOD) PIO Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_OER
value|((AT91_REG *) 	0xFFFFFA10)
end_define

begin_comment
comment|// (PIOD) Output Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_OSR
value|((AT91_REG *) 	0xFFFFFA18)
end_define

begin_comment
comment|// (PIOD) Output Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IFER
value|((AT91_REG *) 	0xFFFFFA20)
end_define

begin_comment
comment|// (PIOD) Input Filter Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_BSR
value|((AT91_REG *) 	0xFFFFFA74)
end_define

begin_comment
comment|// (PIOD) Select B Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IFDR
value|((AT91_REG *) 	0xFFFFFA24)
end_define

begin_comment
comment|// (PIOD) Input Filter Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOD_IFSR
value|((AT91_REG *) 	0xFFFFFA28)
end_define

begin_comment
comment|// (PIOD) Input Filter Status Register
end_comment

begin_comment
comment|// ========== Register definition for PIOC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IFDR
value|((AT91_REG *) 	0xFFFFF824)
end_define

begin_comment
comment|// (PIOC) Input Filter Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_ODR
value|((AT91_REG *) 	0xFFFFF814)
end_define

begin_comment
comment|// (PIOC) Output Disable Registerr
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_ABSR
value|((AT91_REG *) 	0xFFFFF878)
end_define

begin_comment
comment|// (PIOC) AB Select Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_SODR
value|((AT91_REG *) 	0xFFFFF830)
end_define

begin_comment
comment|// (PIOC) Set Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IFSR
value|((AT91_REG *) 	0xFFFFF828)
end_define

begin_comment
comment|// (PIOC) Input Filter Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_CODR
value|((AT91_REG *) 	0xFFFFF834)
end_define

begin_comment
comment|// (PIOC) Clear Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_ODSR
value|((AT91_REG *) 	0xFFFFF838)
end_define

begin_comment
comment|// (PIOC) Output Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IER
value|((AT91_REG *) 	0xFFFFF840)
end_define

begin_comment
comment|// (PIOC) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IMR
value|((AT91_REG *) 	0xFFFFF848)
end_define

begin_comment
comment|// (PIOC) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_OWDR
value|((AT91_REG *) 	0xFFFFF8A4)
end_define

begin_comment
comment|// (PIOC) Output Write Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_MDDR
value|((AT91_REG *) 	0xFFFFF854)
end_define

begin_comment
comment|// (PIOC) Multi-driver Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PDSR
value|((AT91_REG *) 	0xFFFFF83C)
end_define

begin_comment
comment|// (PIOC) Pin Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IDR
value|((AT91_REG *) 	0xFFFFF844)
end_define

begin_comment
comment|// (PIOC) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_ISR
value|((AT91_REG *) 	0xFFFFF84C)
end_define

begin_comment
comment|// (PIOC) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PDR
value|((AT91_REG *) 	0xFFFFF804)
end_define

begin_comment
comment|// (PIOC) PIO Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_OWSR
value|((AT91_REG *) 	0xFFFFF8A8)
end_define

begin_comment
comment|// (PIOC) Output Write Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_OWER
value|((AT91_REG *) 	0xFFFFF8A0)
end_define

begin_comment
comment|// (PIOC) Output Write Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_ASR
value|((AT91_REG *) 	0xFFFFF870)
end_define

begin_comment
comment|// (PIOC) Select A Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PPUSR
value|((AT91_REG *) 	0xFFFFF868)
end_define

begin_comment
comment|// (PIOC) Pad Pull-up Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PPUDR
value|((AT91_REG *) 	0xFFFFF860)
end_define

begin_comment
comment|// (PIOC) Pull-up Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_MDSR
value|((AT91_REG *) 	0xFFFFF858)
end_define

begin_comment
comment|// (PIOC) Multi-driver Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_MDER
value|((AT91_REG *) 	0xFFFFF850)
end_define

begin_comment
comment|// (PIOC) Multi-driver Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_IFER
value|((AT91_REG *) 	0xFFFFF820)
end_define

begin_comment
comment|// (PIOC) Input Filter Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_OSR
value|((AT91_REG *) 	0xFFFFF818)
end_define

begin_comment
comment|// (PIOC) Output Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_OER
value|((AT91_REG *) 	0xFFFFF810)
end_define

begin_comment
comment|// (PIOC) Output Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PSR
value|((AT91_REG *) 	0xFFFFF808)
end_define

begin_comment
comment|// (PIOC) PIO Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PER
value|((AT91_REG *) 	0xFFFFF800)
end_define

begin_comment
comment|// (PIOC) PIO Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_BSR
value|((AT91_REG *) 	0xFFFFF874)
end_define

begin_comment
comment|// (PIOC) Select B Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOC_PPUER
value|((AT91_REG *) 	0xFFFFF864)
end_define

begin_comment
comment|// (PIOC) Pull-up Enable Register
end_comment

begin_comment
comment|// ========== Register definition for PIOB peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_OWSR
value|((AT91_REG *) 	0xFFFFF6A8)
end_define

begin_comment
comment|// (PIOB) Output Write Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PPUSR
value|((AT91_REG *) 	0xFFFFF668)
end_define

begin_comment
comment|// (PIOB) Pad Pull-up Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PPUDR
value|((AT91_REG *) 	0xFFFFF660)
end_define

begin_comment
comment|// (PIOB) Pull-up Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_MDSR
value|((AT91_REG *) 	0xFFFFF658)
end_define

begin_comment
comment|// (PIOB) Multi-driver Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_MDER
value|((AT91_REG *) 	0xFFFFF650)
end_define

begin_comment
comment|// (PIOB) Multi-driver Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IMR
value|((AT91_REG *) 	0xFFFFF648)
end_define

begin_comment
comment|// (PIOB) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_OSR
value|((AT91_REG *) 	0xFFFFF618)
end_define

begin_comment
comment|// (PIOB) Output Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_OER
value|((AT91_REG *) 	0xFFFFF610)
end_define

begin_comment
comment|// (PIOB) Output Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PSR
value|((AT91_REG *) 	0xFFFFF608)
end_define

begin_comment
comment|// (PIOB) PIO Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PER
value|((AT91_REG *) 	0xFFFFF600)
end_define

begin_comment
comment|// (PIOB) PIO Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_BSR
value|((AT91_REG *) 	0xFFFFF674)
end_define

begin_comment
comment|// (PIOB) Select B Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PPUER
value|((AT91_REG *) 	0xFFFFF664)
end_define

begin_comment
comment|// (PIOB) Pull-up Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IFDR
value|((AT91_REG *) 	0xFFFFF624)
end_define

begin_comment
comment|// (PIOB) Input Filter Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_ODR
value|((AT91_REG *) 	0xFFFFF614)
end_define

begin_comment
comment|// (PIOB) Output Disable Registerr
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_ABSR
value|((AT91_REG *) 	0xFFFFF678)
end_define

begin_comment
comment|// (PIOB) AB Select Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_ASR
value|((AT91_REG *) 	0xFFFFF670)
end_define

begin_comment
comment|// (PIOB) Select A Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IFER
value|((AT91_REG *) 	0xFFFFF620)
end_define

begin_comment
comment|// (PIOB) Input Filter Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IFSR
value|((AT91_REG *) 	0xFFFFF628)
end_define

begin_comment
comment|// (PIOB) Input Filter Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_SODR
value|((AT91_REG *) 	0xFFFFF630)
end_define

begin_comment
comment|// (PIOB) Set Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_ODSR
value|((AT91_REG *) 	0xFFFFF638)
end_define

begin_comment
comment|// (PIOB) Output Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_CODR
value|((AT91_REG *) 	0xFFFFF634)
end_define

begin_comment
comment|// (PIOB) Clear Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PDSR
value|((AT91_REG *) 	0xFFFFF63C)
end_define

begin_comment
comment|// (PIOB) Pin Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_OWER
value|((AT91_REG *) 	0xFFFFF6A0)
end_define

begin_comment
comment|// (PIOB) Output Write Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IER
value|((AT91_REG *) 	0xFFFFF640)
end_define

begin_comment
comment|// (PIOB) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_OWDR
value|((AT91_REG *) 	0xFFFFF6A4)
end_define

begin_comment
comment|// (PIOB) Output Write Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_MDDR
value|((AT91_REG *) 	0xFFFFF654)
end_define

begin_comment
comment|// (PIOB) Multi-driver Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_ISR
value|((AT91_REG *) 	0xFFFFF64C)
end_define

begin_comment
comment|// (PIOB) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_IDR
value|((AT91_REG *) 	0xFFFFF644)
end_define

begin_comment
comment|// (PIOB) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOB_PDR
value|((AT91_REG *) 	0xFFFFF604)
end_define

begin_comment
comment|// (PIOB) PIO Disable Register
end_comment

begin_comment
comment|// ========== Register definition for PIOA peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IMR
value|((AT91_REG *) 	0xFFFFF448)
end_define

begin_comment
comment|// (PIOA) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IER
value|((AT91_REG *) 	0xFFFFF440)
end_define

begin_comment
comment|// (PIOA) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_OWDR
value|((AT91_REG *) 	0xFFFFF4A4)
end_define

begin_comment
comment|// (PIOA) Output Write Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_ISR
value|((AT91_REG *) 	0xFFFFF44C)
end_define

begin_comment
comment|// (PIOA) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PPUDR
value|((AT91_REG *) 	0xFFFFF460)
end_define

begin_comment
comment|// (PIOA) Pull-up Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_MDSR
value|((AT91_REG *) 	0xFFFFF458)
end_define

begin_comment
comment|// (PIOA) Multi-driver Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_MDER
value|((AT91_REG *) 	0xFFFFF450)
end_define

begin_comment
comment|// (PIOA) Multi-driver Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PER
value|((AT91_REG *) 	0xFFFFF400)
end_define

begin_comment
comment|// (PIOA) PIO Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PSR
value|((AT91_REG *) 	0xFFFFF408)
end_define

begin_comment
comment|// (PIOA) PIO Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_OER
value|((AT91_REG *) 	0xFFFFF410)
end_define

begin_comment
comment|// (PIOA) Output Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_BSR
value|((AT91_REG *) 	0xFFFFF474)
end_define

begin_comment
comment|// (PIOA) Select B Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PPUER
value|((AT91_REG *) 	0xFFFFF464)
end_define

begin_comment
comment|// (PIOA) Pull-up Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_MDDR
value|((AT91_REG *) 	0xFFFFF454)
end_define

begin_comment
comment|// (PIOA) Multi-driver Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PDR
value|((AT91_REG *) 	0xFFFFF404)
end_define

begin_comment
comment|// (PIOA) PIO Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_ODR
value|((AT91_REG *) 	0xFFFFF414)
end_define

begin_comment
comment|// (PIOA) Output Disable Registerr
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IFDR
value|((AT91_REG *) 	0xFFFFF424)
end_define

begin_comment
comment|// (PIOA) Input Filter Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_ABSR
value|((AT91_REG *) 	0xFFFFF478)
end_define

begin_comment
comment|// (PIOA) AB Select Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_ASR
value|((AT91_REG *) 	0xFFFFF470)
end_define

begin_comment
comment|// (PIOA) Select A Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PPUSR
value|((AT91_REG *) 	0xFFFFF468)
end_define

begin_comment
comment|// (PIOA) Pad Pull-up Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_ODSR
value|((AT91_REG *) 	0xFFFFF438)
end_define

begin_comment
comment|// (PIOA) Output Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_SODR
value|((AT91_REG *) 	0xFFFFF430)
end_define

begin_comment
comment|// (PIOA) Set Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IFSR
value|((AT91_REG *) 	0xFFFFF428)
end_define

begin_comment
comment|// (PIOA) Input Filter Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IFER
value|((AT91_REG *) 	0xFFFFF420)
end_define

begin_comment
comment|// (PIOA) Input Filter Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_OSR
value|((AT91_REG *) 	0xFFFFF418)
end_define

begin_comment
comment|// (PIOA) Output Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_IDR
value|((AT91_REG *) 	0xFFFFF444)
end_define

begin_comment
comment|// (PIOA) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_PDSR
value|((AT91_REG *) 	0xFFFFF43C)
end_define

begin_comment
comment|// (PIOA) Pin Data Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_CODR
value|((AT91_REG *) 	0xFFFFF434)
end_define

begin_comment
comment|// (PIOA) Clear Output Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_OWSR
value|((AT91_REG *) 	0xFFFFF4A8)
end_define

begin_comment
comment|// (PIOA) Output Write Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_PIOA_OWER
value|((AT91_REG *) 	0xFFFFF4A0)
end_define

begin_comment
comment|// (PIOA) Output Write Enable Register
end_comment

begin_comment
comment|// ========== Register definition for DBGU peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_C2R
value|((AT91_REG *) 	0xFFFFF244)
end_define

begin_comment
comment|// (DBGU) Chip ID2 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_THR
value|((AT91_REG *) 	0xFFFFF21C)
end_define

begin_comment
comment|// (DBGU) Transmitter Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_CSR
value|((AT91_REG *) 	0xFFFFF214)
end_define

begin_comment
comment|// (DBGU) Channel Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_IDR
value|((AT91_REG *) 	0xFFFFF20C)
end_define

begin_comment
comment|// (DBGU) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_MR
value|((AT91_REG *) 	0xFFFFF204)
end_define

begin_comment
comment|// (DBGU) Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_FNTR
value|((AT91_REG *) 	0xFFFFF248)
end_define

begin_comment
comment|// (DBGU) Force NTRST Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_C1R
value|((AT91_REG *) 	0xFFFFF240)
end_define

begin_comment
comment|// (DBGU) Chip ID1 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_BRGR
value|((AT91_REG *) 	0xFFFFF220)
end_define

begin_comment
comment|// (DBGU) Baud Rate Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_RHR
value|((AT91_REG *) 	0xFFFFF218)
end_define

begin_comment
comment|// (DBGU) Receiver Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_IMR
value|((AT91_REG *) 	0xFFFFF210)
end_define

begin_comment
comment|// (DBGU) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_IER
value|((AT91_REG *) 	0xFFFFF208)
end_define

begin_comment
comment|// (DBGU) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_CR
value|((AT91_REG *) 	0xFFFFF200)
end_define

begin_comment
comment|// (DBGU) Control Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_DBGU peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_TNCR
value|((AT91_REG *) 	0xFFFFF31C)
end_define

begin_comment
comment|// (PDC_DBGU) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_RNCR
value|((AT91_REG *) 	0xFFFFF314)
end_define

begin_comment
comment|// (PDC_DBGU) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_PTCR
value|((AT91_REG *) 	0xFFFFF320)
end_define

begin_comment
comment|// (PDC_DBGU) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_PTSR
value|((AT91_REG *) 	0xFFFFF324)
end_define

begin_comment
comment|// (PDC_DBGU) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_RCR
value|((AT91_REG *) 	0xFFFFF304)
end_define

begin_comment
comment|// (PDC_DBGU) Receive Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_TCR
value|((AT91_REG *) 	0xFFFFF30C)
end_define

begin_comment
comment|// (PDC_DBGU) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_RPR
value|((AT91_REG *) 	0xFFFFF300)
end_define

begin_comment
comment|// (PDC_DBGU) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_TPR
value|((AT91_REG *) 	0xFFFFF308)
end_define

begin_comment
comment|// (PDC_DBGU) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_RNPR
value|((AT91_REG *) 	0xFFFFF310)
end_define

begin_comment
comment|// (PDC_DBGU) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_DBGU_TNPR
value|((AT91_REG *) 	0xFFFFF318)
end_define

begin_comment
comment|// (PDC_DBGU) Transmit Next Pointer Register
end_comment

begin_comment
comment|// ========== Register definition for AIC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_ICCR
value|((AT91_REG *) 	0xFFFFF128)
end_define

begin_comment
comment|// (AIC) Interrupt Clear Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_IECR
value|((AT91_REG *) 	0xFFFFF120)
end_define

begin_comment
comment|// (AIC) Interrupt Enable Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SMR
value|((AT91_REG *) 	0xFFFFF000)
end_define

begin_comment
comment|// (AIC) Source Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_ISCR
value|((AT91_REG *) 	0xFFFFF12C)
end_define

begin_comment
comment|// (AIC) Interrupt Set Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_EOICR
value|((AT91_REG *) 	0xFFFFF130)
end_define

begin_comment
comment|// (AIC) End of Interrupt Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_DCR
value|((AT91_REG *) 	0xFFFFF138)
end_define

begin_comment
comment|// (AIC) Debug Control Register (Protect)
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_FFER
value|((AT91_REG *) 	0xFFFFF140)
end_define

begin_comment
comment|// (AIC) Fast Forcing Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SVR
value|((AT91_REG *) 	0xFFFFF080)
end_define

begin_comment
comment|// (AIC) Source Vector Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_SPU
value|((AT91_REG *) 	0xFFFFF134)
end_define

begin_comment
comment|// (AIC) Spurious Vector Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_FFDR
value|((AT91_REG *) 	0xFFFFF144)
end_define

begin_comment
comment|// (AIC) Fast Forcing Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_FVR
value|((AT91_REG *) 	0xFFFFF104)
end_define

begin_comment
comment|// (AIC) FIQ Vector Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_FFSR
value|((AT91_REG *) 	0xFFFFF148)
end_define

begin_comment
comment|// (AIC) Fast Forcing Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_IMR
value|((AT91_REG *) 	0xFFFFF110)
end_define

begin_comment
comment|// (AIC) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_ISR
value|((AT91_REG *) 	0xFFFFF108)
end_define

begin_comment
comment|// (AIC) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_IVR
value|((AT91_REG *) 	0xFFFFF100)
end_define

begin_comment
comment|// (AIC) IRQ Vector Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_IDCR
value|((AT91_REG *) 	0xFFFFF124)
end_define

begin_comment
comment|// (AIC) Interrupt Disable Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_CISR
value|((AT91_REG *) 	0xFFFFF114)
end_define

begin_comment
comment|// (AIC) Core Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_AIC_IPR
value|((AT91_REG *) 	0xFFFFF10C)
end_define

begin_comment
comment|// (AIC) Interrupt Pending Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_SPI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PTCR
value|((AT91_REG *) 	0xFFFE0120)
end_define

begin_comment
comment|// (PDC_SPI) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TNPR
value|((AT91_REG *) 	0xFFFE0118)
end_define

begin_comment
comment|// (PDC_SPI) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RNPR
value|((AT91_REG *) 	0xFFFE0110)
end_define

begin_comment
comment|// (PDC_SPI) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TPR
value|((AT91_REG *) 	0xFFFE0108)
end_define

begin_comment
comment|// (PDC_SPI) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RPR
value|((AT91_REG *) 	0xFFFE0100)
end_define

begin_comment
comment|// (PDC_SPI) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_PTSR
value|((AT91_REG *) 	0xFFFE0124)
end_define

begin_comment
comment|// (PDC_SPI) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TNCR
value|((AT91_REG *) 	0xFFFE011C)
end_define

begin_comment
comment|// (PDC_SPI) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RNCR
value|((AT91_REG *) 	0xFFFE0114)
end_define

begin_comment
comment|// (PDC_SPI) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TCR
value|((AT91_REG *) 	0xFFFE010C)
end_define

begin_comment
comment|// (PDC_SPI) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RCR
value|((AT91_REG *) 	0xFFFE0104)
end_define

begin_comment
comment|// (PDC_SPI) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for SPI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_CSR
value|((AT91_REG *) 	0xFFFE0030)
end_define

begin_comment
comment|// (SPI) Chip Select Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_IDR
value|((AT91_REG *) 	0xFFFE0018)
end_define

begin_comment
comment|// (SPI) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_SR
value|((AT91_REG *) 	0xFFFE0010)
end_define

begin_comment
comment|// (SPI) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_RDR
value|((AT91_REG *) 	0xFFFE0008)
end_define

begin_comment
comment|// (SPI) Receive Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_CR
value|((AT91_REG *) 	0xFFFE0000)
end_define

begin_comment
comment|// (SPI) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_IMR
value|((AT91_REG *) 	0xFFFE001C)
end_define

begin_comment
comment|// (SPI) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_IER
value|((AT91_REG *) 	0xFFFE0014)
end_define

begin_comment
comment|// (SPI) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_TDR
value|((AT91_REG *) 	0xFFFE000C)
end_define

begin_comment
comment|// (SPI) Transmit Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SPI_MR
value|((AT91_REG *) 	0xFFFE0004)
end_define

begin_comment
comment|// (SPI) Mode Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_SSC2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_PTCR
value|((AT91_REG *) 	0xFFFD8120)
end_define

begin_comment
comment|// (PDC_SSC2) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TNPR
value|((AT91_REG *) 	0xFFFD8118)
end_define

begin_comment
comment|// (PDC_SSC2) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RNPR
value|((AT91_REG *) 	0xFFFD8110)
end_define

begin_comment
comment|// (PDC_SSC2) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TPR
value|((AT91_REG *) 	0xFFFD8108)
end_define

begin_comment
comment|// (PDC_SSC2) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RPR
value|((AT91_REG *) 	0xFFFD8100)
end_define

begin_comment
comment|// (PDC_SSC2) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_PTSR
value|((AT91_REG *) 	0xFFFD8124)
end_define

begin_comment
comment|// (PDC_SSC2) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TNCR
value|((AT91_REG *) 	0xFFFD811C)
end_define

begin_comment
comment|// (PDC_SSC2) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RNCR
value|((AT91_REG *) 	0xFFFD8114)
end_define

begin_comment
comment|// (PDC_SSC2) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TCR
value|((AT91_REG *) 	0xFFFD810C)
end_define

begin_comment
comment|// (PDC_SSC2) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RCR
value|((AT91_REG *) 	0xFFFD8104)
end_define

begin_comment
comment|// (PDC_SSC2) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for SSC2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_IMR
value|((AT91_REG *) 	0xFFFD804C)
end_define

begin_comment
comment|// (SSC2) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_IER
value|((AT91_REG *) 	0xFFFD8044)
end_define

begin_comment
comment|// (SSC2) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RC1R
value|((AT91_REG *) 	0xFFFD803C)
end_define

begin_comment
comment|// (SSC2) Receive Compare 1 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TSHR
value|((AT91_REG *) 	0xFFFD8034)
end_define

begin_comment
comment|// (SSC2) Transmit Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_CMR
value|((AT91_REG *) 	0xFFFD8004)
end_define

begin_comment
comment|// (SSC2) Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_IDR
value|((AT91_REG *) 	0xFFFD8048)
end_define

begin_comment
comment|// (SSC2) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TCMR
value|((AT91_REG *) 	0xFFFD8018)
end_define

begin_comment
comment|// (SSC2) Transmit Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RCMR
value|((AT91_REG *) 	0xFFFD8010)
end_define

begin_comment
comment|// (SSC2) Receive Clock ModeRegister
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_CR
value|((AT91_REG *) 	0xFFFD8000)
end_define

begin_comment
comment|// (SSC2) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RFMR
value|((AT91_REG *) 	0xFFFD8014)
end_define

begin_comment
comment|// (SSC2) Receive Frame Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_TFMR
value|((AT91_REG *) 	0xFFFD801C)
end_define

begin_comment
comment|// (SSC2) Transmit Frame Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_THR
value|((AT91_REG *) 	0xFFFD8024)
end_define

begin_comment
comment|// (SSC2) Transmit Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_SR
value|((AT91_REG *) 	0xFFFD8040)
end_define

begin_comment
comment|// (SSC2) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RC0R
value|((AT91_REG *) 	0xFFFD8038)
end_define

begin_comment
comment|// (SSC2) Receive Compare 0 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RSHR
value|((AT91_REG *) 	0xFFFD8030)
end_define

begin_comment
comment|// (SSC2) Receive Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC2_RHR
value|((AT91_REG *) 	0xFFFD8020)
end_define

begin_comment
comment|// (SSC2) Receive Holding Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_SSC1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_PTCR
value|((AT91_REG *) 	0xFFFD4120)
end_define

begin_comment
comment|// (PDC_SSC1) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TNPR
value|((AT91_REG *) 	0xFFFD4118)
end_define

begin_comment
comment|// (PDC_SSC1) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RNPR
value|((AT91_REG *) 	0xFFFD4110)
end_define

begin_comment
comment|// (PDC_SSC1) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TPR
value|((AT91_REG *) 	0xFFFD4108)
end_define

begin_comment
comment|// (PDC_SSC1) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RPR
value|((AT91_REG *) 	0xFFFD4100)
end_define

begin_comment
comment|// (PDC_SSC1) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_PTSR
value|((AT91_REG *) 	0xFFFD4124)
end_define

begin_comment
comment|// (PDC_SSC1) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TNCR
value|((AT91_REG *) 	0xFFFD411C)
end_define

begin_comment
comment|// (PDC_SSC1) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RNCR
value|((AT91_REG *) 	0xFFFD4114)
end_define

begin_comment
comment|// (PDC_SSC1) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TCR
value|((AT91_REG *) 	0xFFFD410C)
end_define

begin_comment
comment|// (PDC_SSC1) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RCR
value|((AT91_REG *) 	0xFFFD4104)
end_define

begin_comment
comment|// (PDC_SSC1) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for SSC1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RFMR
value|((AT91_REG *) 	0xFFFD4014)
end_define

begin_comment
comment|// (SSC1) Receive Frame Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_CMR
value|((AT91_REG *) 	0xFFFD4004)
end_define

begin_comment
comment|// (SSC1) Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_IDR
value|((AT91_REG *) 	0xFFFD4048)
end_define

begin_comment
comment|// (SSC1) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_SR
value|((AT91_REG *) 	0xFFFD4040)
end_define

begin_comment
comment|// (SSC1) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RC0R
value|((AT91_REG *) 	0xFFFD4038)
end_define

begin_comment
comment|// (SSC1) Receive Compare 0 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RSHR
value|((AT91_REG *) 	0xFFFD4030)
end_define

begin_comment
comment|// (SSC1) Receive Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RHR
value|((AT91_REG *) 	0xFFFD4020)
end_define

begin_comment
comment|// (SSC1) Receive Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TCMR
value|((AT91_REG *) 	0xFFFD4018)
end_define

begin_comment
comment|// (SSC1) Transmit Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RCMR
value|((AT91_REG *) 	0xFFFD4010)
end_define

begin_comment
comment|// (SSC1) Receive Clock ModeRegister
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_CR
value|((AT91_REG *) 	0xFFFD4000)
end_define

begin_comment
comment|// (SSC1) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_IMR
value|((AT91_REG *) 	0xFFFD404C)
end_define

begin_comment
comment|// (SSC1) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_IER
value|((AT91_REG *) 	0xFFFD4044)
end_define

begin_comment
comment|// (SSC1) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_RC1R
value|((AT91_REG *) 	0xFFFD403C)
end_define

begin_comment
comment|// (SSC1) Receive Compare 1 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TSHR
value|((AT91_REG *) 	0xFFFD4034)
end_define

begin_comment
comment|// (SSC1) Transmit Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_THR
value|((AT91_REG *) 	0xFFFD4024)
end_define

begin_comment
comment|// (SSC1) Transmit Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC1_TFMR
value|((AT91_REG *) 	0xFFFD401C)
end_define

begin_comment
comment|// (SSC1) Transmit Frame Mode Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_SSC0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_PTCR
value|((AT91_REG *) 	0xFFFD0120)
end_define

begin_comment
comment|// (PDC_SSC0) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TNPR
value|((AT91_REG *) 	0xFFFD0118)
end_define

begin_comment
comment|// (PDC_SSC0) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RNPR
value|((AT91_REG *) 	0xFFFD0110)
end_define

begin_comment
comment|// (PDC_SSC0) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TPR
value|((AT91_REG *) 	0xFFFD0108)
end_define

begin_comment
comment|// (PDC_SSC0) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RPR
value|((AT91_REG *) 	0xFFFD0100)
end_define

begin_comment
comment|// (PDC_SSC0) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_PTSR
value|((AT91_REG *) 	0xFFFD0124)
end_define

begin_comment
comment|// (PDC_SSC0) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TNCR
value|((AT91_REG *) 	0xFFFD011C)
end_define

begin_comment
comment|// (PDC_SSC0) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RNCR
value|((AT91_REG *) 	0xFFFD0114)
end_define

begin_comment
comment|// (PDC_SSC0) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TCR
value|((AT91_REG *) 	0xFFFD010C)
end_define

begin_comment
comment|// (PDC_SSC0) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RCR
value|((AT91_REG *) 	0xFFFD0104)
end_define

begin_comment
comment|// (PDC_SSC0) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for SSC0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_IMR
value|((AT91_REG *) 	0xFFFD004C)
end_define

begin_comment
comment|// (SSC0) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_IER
value|((AT91_REG *) 	0xFFFD0044)
end_define

begin_comment
comment|// (SSC0) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RC1R
value|((AT91_REG *) 	0xFFFD003C)
end_define

begin_comment
comment|// (SSC0) Receive Compare 1 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TSHR
value|((AT91_REG *) 	0xFFFD0034)
end_define

begin_comment
comment|// (SSC0) Transmit Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_THR
value|((AT91_REG *) 	0xFFFD0024)
end_define

begin_comment
comment|// (SSC0) Transmit Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TFMR
value|((AT91_REG *) 	0xFFFD001C)
end_define

begin_comment
comment|// (SSC0) Transmit Frame Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RFMR
value|((AT91_REG *) 	0xFFFD0014)
end_define

begin_comment
comment|// (SSC0) Receive Frame Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_CMR
value|((AT91_REG *) 	0xFFFD0004)
end_define

begin_comment
comment|// (SSC0) Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_IDR
value|((AT91_REG *) 	0xFFFD0048)
end_define

begin_comment
comment|// (SSC0) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_SR
value|((AT91_REG *) 	0xFFFD0040)
end_define

begin_comment
comment|// (SSC0) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RC0R
value|((AT91_REG *) 	0xFFFD0038)
end_define

begin_comment
comment|// (SSC0) Receive Compare 0 Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RSHR
value|((AT91_REG *) 	0xFFFD0030)
end_define

begin_comment
comment|// (SSC0) Receive Sync Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RHR
value|((AT91_REG *) 	0xFFFD0020)
end_define

begin_comment
comment|// (SSC0) Receive Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_TCMR
value|((AT91_REG *) 	0xFFFD0018)
end_define

begin_comment
comment|// (SSC0) Transmit Clock Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_RCMR
value|((AT91_REG *) 	0xFFFD0010)
end_define

begin_comment
comment|// (SSC0) Receive Clock ModeRegister
end_comment

begin_define
define|#
directive|define
name|AT91C_SSC0_CR
value|((AT91_REG *) 	0xFFFD0000)
end_define

begin_comment
comment|// (SSC0) Control Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_US3 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_PTSR
value|((AT91_REG *) 	0xFFFCC124)
end_define

begin_comment
comment|// (PDC_US3) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_TNCR
value|((AT91_REG *) 	0xFFFCC11C)
end_define

begin_comment
comment|// (PDC_US3) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RNCR
value|((AT91_REG *) 	0xFFFCC114)
end_define

begin_comment
comment|// (PDC_US3) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_TCR
value|((AT91_REG *) 	0xFFFCC10C)
end_define

begin_comment
comment|// (PDC_US3) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RCR
value|((AT91_REG *) 	0xFFFCC104)
end_define

begin_comment
comment|// (PDC_US3) Receive Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_PTCR
value|((AT91_REG *) 	0xFFFCC120)
end_define

begin_comment
comment|// (PDC_US3) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_TNPR
value|((AT91_REG *) 	0xFFFCC118)
end_define

begin_comment
comment|// (PDC_US3) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RNPR
value|((AT91_REG *) 	0xFFFCC110)
end_define

begin_comment
comment|// (PDC_US3) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_TPR
value|((AT91_REG *) 	0xFFFCC108)
end_define

begin_comment
comment|// (PDC_US3) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RPR
value|((AT91_REG *) 	0xFFFCC100)
end_define

begin_comment
comment|// (PDC_US3) Receive Pointer Register
end_comment

begin_comment
comment|// ========== Register definition for US3 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_IF
value|((AT91_REG *) 	0xFFFCC04C)
end_define

begin_comment
comment|// (US3) IRDA_FILTER Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_NER
value|((AT91_REG *) 	0xFFFCC044)
end_define

begin_comment
comment|// (US3) Nb Errors Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RTOR
value|((AT91_REG *) 	0xFFFCC024)
end_define

begin_comment
comment|// (US3) Receiver Time-out Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_THR
value|((AT91_REG *) 	0xFFFCC01C)
end_define

begin_comment
comment|// (US3) Transmitter Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_CSR
value|((AT91_REG *) 	0xFFFCC014)
end_define

begin_comment
comment|// (US3) Channel Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_IDR
value|((AT91_REG *) 	0xFFFCC00C)
end_define

begin_comment
comment|// (US3) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_MR
value|((AT91_REG *) 	0xFFFCC004)
end_define

begin_comment
comment|// (US3) Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_XXR
value|((AT91_REG *) 	0xFFFCC048)
end_define

begin_comment
comment|// (US3) XON_XOFF Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_FIDI
value|((AT91_REG *) 	0xFFFCC040)
end_define

begin_comment
comment|// (US3) FI_DI_Ratio Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_TTGR
value|((AT91_REG *) 	0xFFFCC028)
end_define

begin_comment
comment|// (US3) Transmitter Time-guard Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_BRGR
value|((AT91_REG *) 	0xFFFCC020)
end_define

begin_comment
comment|// (US3) Baud Rate Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_RHR
value|((AT91_REG *) 	0xFFFCC018)
end_define

begin_comment
comment|// (US3) Receiver Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_IMR
value|((AT91_REG *) 	0xFFFCC010)
end_define

begin_comment
comment|// (US3) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_IER
value|((AT91_REG *) 	0xFFFCC008)
end_define

begin_comment
comment|// (US3) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US3_CR
value|((AT91_REG *) 	0xFFFCC000)
end_define

begin_comment
comment|// (US3) Control Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_US2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_PTSR
value|((AT91_REG *) 	0xFFFC8124)
end_define

begin_comment
comment|// (PDC_US2) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_TNCR
value|((AT91_REG *) 	0xFFFC811C)
end_define

begin_comment
comment|// (PDC_US2) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RNCR
value|((AT91_REG *) 	0xFFFC8114)
end_define

begin_comment
comment|// (PDC_US2) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_TCR
value|((AT91_REG *) 	0xFFFC810C)
end_define

begin_comment
comment|// (PDC_US2) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_PTCR
value|((AT91_REG *) 	0xFFFC8120)
end_define

begin_comment
comment|// (PDC_US2) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RCR
value|((AT91_REG *) 	0xFFFC8104)
end_define

begin_comment
comment|// (PDC_US2) Receive Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_TNPR
value|((AT91_REG *) 	0xFFFC8118)
end_define

begin_comment
comment|// (PDC_US2) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RPR
value|((AT91_REG *) 	0xFFFC8100)
end_define

begin_comment
comment|// (PDC_US2) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_TPR
value|((AT91_REG *) 	0xFFFC8108)
end_define

begin_comment
comment|// (PDC_US2) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RNPR
value|((AT91_REG *) 	0xFFFC8110)
end_define

begin_comment
comment|// (PDC_US2) Receive Next Pointer Register
end_comment

begin_comment
comment|// ========== Register definition for US2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_XXR
value|((AT91_REG *) 	0xFFFC8048)
end_define

begin_comment
comment|// (US2) XON_XOFF Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_FIDI
value|((AT91_REG *) 	0xFFFC8040)
end_define

begin_comment
comment|// (US2) FI_DI_Ratio Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_TTGR
value|((AT91_REG *) 	0xFFFC8028)
end_define

begin_comment
comment|// (US2) Transmitter Time-guard Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_BRGR
value|((AT91_REG *) 	0xFFFC8020)
end_define

begin_comment
comment|// (US2) Baud Rate Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RHR
value|((AT91_REG *) 	0xFFFC8018)
end_define

begin_comment
comment|// (US2) Receiver Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_IMR
value|((AT91_REG *) 	0xFFFC8010)
end_define

begin_comment
comment|// (US2) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_IER
value|((AT91_REG *) 	0xFFFC8008)
end_define

begin_comment
comment|// (US2) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_CR
value|((AT91_REG *) 	0xFFFC8000)
end_define

begin_comment
comment|// (US2) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_IF
value|((AT91_REG *) 	0xFFFC804C)
end_define

begin_comment
comment|// (US2) IRDA_FILTER Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_NER
value|((AT91_REG *) 	0xFFFC8044)
end_define

begin_comment
comment|// (US2) Nb Errors Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_RTOR
value|((AT91_REG *) 	0xFFFC8024)
end_define

begin_comment
comment|// (US2) Receiver Time-out Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_THR
value|((AT91_REG *) 	0xFFFC801C)
end_define

begin_comment
comment|// (US2) Transmitter Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_CSR
value|((AT91_REG *) 	0xFFFC8014)
end_define

begin_comment
comment|// (US2) Channel Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_IDR
value|((AT91_REG *) 	0xFFFC800C)
end_define

begin_comment
comment|// (US2) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US2_MR
value|((AT91_REG *) 	0xFFFC8004)
end_define

begin_comment
comment|// (US2) Mode Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_US1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_PTSR
value|((AT91_REG *) 	0xFFFC4124)
end_define

begin_comment
comment|// (PDC_US1) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_TNCR
value|((AT91_REG *) 	0xFFFC411C)
end_define

begin_comment
comment|// (PDC_US1) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RNCR
value|((AT91_REG *) 	0xFFFC4114)
end_define

begin_comment
comment|// (PDC_US1) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_TCR
value|((AT91_REG *) 	0xFFFC410C)
end_define

begin_comment
comment|// (PDC_US1) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RCR
value|((AT91_REG *) 	0xFFFC4104)
end_define

begin_comment
comment|// (PDC_US1) Receive Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_PTCR
value|((AT91_REG *) 	0xFFFC4120)
end_define

begin_comment
comment|// (PDC_US1) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_TNPR
value|((AT91_REG *) 	0xFFFC4118)
end_define

begin_comment
comment|// (PDC_US1) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RNPR
value|((AT91_REG *) 	0xFFFC4110)
end_define

begin_comment
comment|// (PDC_US1) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_TPR
value|((AT91_REG *) 	0xFFFC4108)
end_define

begin_comment
comment|// (PDC_US1) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RPR
value|((AT91_REG *) 	0xFFFC4100)
end_define

begin_comment
comment|// (PDC_US1) Receive Pointer Register
end_comment

begin_comment
comment|// ========== Register definition for US1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_XXR
value|((AT91_REG *) 	0xFFFC4048)
end_define

begin_comment
comment|// (US1) XON_XOFF Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RHR
value|((AT91_REG *) 	0xFFFC4018)
end_define

begin_comment
comment|// (US1) Receiver Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_IMR
value|((AT91_REG *) 	0xFFFC4010)
end_define

begin_comment
comment|// (US1) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_IER
value|((AT91_REG *) 	0xFFFC4008)
end_define

begin_comment
comment|// (US1) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_CR
value|((AT91_REG *) 	0xFFFC4000)
end_define

begin_comment
comment|// (US1) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_RTOR
value|((AT91_REG *) 	0xFFFC4024)
end_define

begin_comment
comment|// (US1) Receiver Time-out Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_THR
value|((AT91_REG *) 	0xFFFC401C)
end_define

begin_comment
comment|// (US1) Transmitter Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_CSR
value|((AT91_REG *) 	0xFFFC4014)
end_define

begin_comment
comment|// (US1) Channel Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_IDR
value|((AT91_REG *) 	0xFFFC400C)
end_define

begin_comment
comment|// (US1) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_FIDI
value|((AT91_REG *) 	0xFFFC4040)
end_define

begin_comment
comment|// (US1) FI_DI_Ratio Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_BRGR
value|((AT91_REG *) 	0xFFFC4020)
end_define

begin_comment
comment|// (US1) Baud Rate Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_TTGR
value|((AT91_REG *) 	0xFFFC4028)
end_define

begin_comment
comment|// (US1) Transmitter Time-guard Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_IF
value|((AT91_REG *) 	0xFFFC404C)
end_define

begin_comment
comment|// (US1) IRDA_FILTER Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_NER
value|((AT91_REG *) 	0xFFFC4044)
end_define

begin_comment
comment|// (US1) Nb Errors Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US1_MR
value|((AT91_REG *) 	0xFFFC4004)
end_define

begin_comment
comment|// (US1) Mode Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_US0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_PTCR
value|((AT91_REG *) 	0xFFFC0120)
end_define

begin_comment
comment|// (PDC_US0) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_TNPR
value|((AT91_REG *) 	0xFFFC0118)
end_define

begin_comment
comment|// (PDC_US0) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RNPR
value|((AT91_REG *) 	0xFFFC0110)
end_define

begin_comment
comment|// (PDC_US0) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_TPR
value|((AT91_REG *) 	0xFFFC0108)
end_define

begin_comment
comment|// (PDC_US0) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RPR
value|((AT91_REG *) 	0xFFFC0100)
end_define

begin_comment
comment|// (PDC_US0) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_PTSR
value|((AT91_REG *) 	0xFFFC0124)
end_define

begin_comment
comment|// (PDC_US0) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_TNCR
value|((AT91_REG *) 	0xFFFC011C)
end_define

begin_comment
comment|// (PDC_US0) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RNCR
value|((AT91_REG *) 	0xFFFC0114)
end_define

begin_comment
comment|// (PDC_US0) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_TCR
value|((AT91_REG *) 	0xFFFC010C)
end_define

begin_comment
comment|// (PDC_US0) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RCR
value|((AT91_REG *) 	0xFFFC0104)
end_define

begin_comment
comment|// (PDC_US0) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for US0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_TTGR
value|((AT91_REG *) 	0xFFFC0028)
end_define

begin_comment
comment|// (US0) Transmitter Time-guard Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_BRGR
value|((AT91_REG *) 	0xFFFC0020)
end_define

begin_comment
comment|// (US0) Baud Rate Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RHR
value|((AT91_REG *) 	0xFFFC0018)
end_define

begin_comment
comment|// (US0) Receiver Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_IMR
value|((AT91_REG *) 	0xFFFC0010)
end_define

begin_comment
comment|// (US0) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_NER
value|((AT91_REG *) 	0xFFFC0044)
end_define

begin_comment
comment|// (US0) Nb Errors Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_RTOR
value|((AT91_REG *) 	0xFFFC0024)
end_define

begin_comment
comment|// (US0) Receiver Time-out Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_XXR
value|((AT91_REG *) 	0xFFFC0048)
end_define

begin_comment
comment|// (US0) XON_XOFF Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_FIDI
value|((AT91_REG *) 	0xFFFC0040)
end_define

begin_comment
comment|// (US0) FI_DI_Ratio Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_CR
value|((AT91_REG *) 	0xFFFC0000)
end_define

begin_comment
comment|// (US0) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_IER
value|((AT91_REG *) 	0xFFFC0008)
end_define

begin_comment
comment|// (US0) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_IF
value|((AT91_REG *) 	0xFFFC004C)
end_define

begin_comment
comment|// (US0) IRDA_FILTER Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_MR
value|((AT91_REG *) 	0xFFFC0004)
end_define

begin_comment
comment|// (US0) Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_IDR
value|((AT91_REG *) 	0xFFFC000C)
end_define

begin_comment
comment|// (US0) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_CSR
value|((AT91_REG *) 	0xFFFC0014)
end_define

begin_comment
comment|// (US0) Channel Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_US0_THR
value|((AT91_REG *) 	0xFFFC001C)
end_define

begin_comment
comment|// (US0) Transmitter Holding Register
end_comment

begin_comment
comment|// ========== Register definition for TWI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_RHR
value|((AT91_REG *) 	0xFFFB8030)
end_define

begin_comment
comment|// (TWI) Receive Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IDR
value|((AT91_REG *) 	0xFFFB8028)
end_define

begin_comment
comment|// (TWI) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SR
value|((AT91_REG *) 	0xFFFB8020)
end_define

begin_comment
comment|// (TWI) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_CWGR
value|((AT91_REG *) 	0xFFFB8010)
end_define

begin_comment
comment|// (TWI) Clock Waveform Generator Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_SMR
value|((AT91_REG *) 	0xFFFB8008)
end_define

begin_comment
comment|// (TWI) Slave Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_CR
value|((AT91_REG *) 	0xFFFB8000)
end_define

begin_comment
comment|// (TWI) Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_THR
value|((AT91_REG *) 	0xFFFB8034)
end_define

begin_comment
comment|// (TWI) Transmit Holding Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IMR
value|((AT91_REG *) 	0xFFFB802C)
end_define

begin_comment
comment|// (TWI) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IER
value|((AT91_REG *) 	0xFFFB8024)
end_define

begin_comment
comment|// (TWI) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_IADR
value|((AT91_REG *) 	0xFFFB800C)
end_define

begin_comment
comment|// (TWI) Internal Address Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TWI_MMR
value|((AT91_REG *) 	0xFFFB8004)
end_define

begin_comment
comment|// (TWI) Master Mode Register
end_comment

begin_comment
comment|// ========== Register definition for PDC_MCI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PTCR
value|((AT91_REG *) 	0xFFFB4120)
end_define

begin_comment
comment|// (PDC_MCI) PDC Transfer Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TNPR
value|((AT91_REG *) 	0xFFFB4118)
end_define

begin_comment
comment|// (PDC_MCI) Transmit Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RNPR
value|((AT91_REG *) 	0xFFFB4110)
end_define

begin_comment
comment|// (PDC_MCI) Receive Next Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TPR
value|((AT91_REG *) 	0xFFFB4108)
end_define

begin_comment
comment|// (PDC_MCI) Transmit Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RPR
value|((AT91_REG *) 	0xFFFB4100)
end_define

begin_comment
comment|// (PDC_MCI) Receive Pointer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_PTSR
value|((AT91_REG *) 	0xFFFB4124)
end_define

begin_comment
comment|// (PDC_MCI) PDC Transfer Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TNCR
value|((AT91_REG *) 	0xFFFB411C)
end_define

begin_comment
comment|// (PDC_MCI) Transmit Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RNCR
value|((AT91_REG *) 	0xFFFB4114)
end_define

begin_comment
comment|// (PDC_MCI) Receive Next Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TCR
value|((AT91_REG *) 	0xFFFB410C)
end_define

begin_comment
comment|// (PDC_MCI) Transmit Counter Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RCR
value|((AT91_REG *) 	0xFFFB4104)
end_define

begin_comment
comment|// (PDC_MCI) Receive Counter Register
end_comment

begin_comment
comment|// ========== Register definition for MCI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_IDR
value|((AT91_REG *) 	0xFFFB4048)
end_define

begin_comment
comment|// (MCI) MCI Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SR
value|((AT91_REG *) 	0xFFFB4040)
end_define

begin_comment
comment|// (MCI) MCI Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RDR
value|((AT91_REG *) 	0xFFFB4030)
end_define

begin_comment
comment|// (MCI) MCI Receive Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_RSPR
value|((AT91_REG *) 	0xFFFB4020)
end_define

begin_comment
comment|// (MCI) MCI Response Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_ARGR
value|((AT91_REG *) 	0xFFFB4010)
end_define

begin_comment
comment|// (MCI) MCI Argument Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_DTOR
value|((AT91_REG *) 	0xFFFB4008)
end_define

begin_comment
comment|// (MCI) MCI Data Timeout Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_CR
value|((AT91_REG *) 	0xFFFB4000)
end_define

begin_comment
comment|// (MCI) MCI Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_IMR
value|((AT91_REG *) 	0xFFFB404C)
end_define

begin_comment
comment|// (MCI) MCI Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_IER
value|((AT91_REG *) 	0xFFFB4044)
end_define

begin_comment
comment|// (MCI) MCI Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_TDR
value|((AT91_REG *) 	0xFFFB4034)
end_define

begin_comment
comment|// (MCI) MCI Transmit Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_CMDR
value|((AT91_REG *) 	0xFFFB4014)
end_define

begin_comment
comment|// (MCI) MCI Command Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SDCR
value|((AT91_REG *) 	0xFFFB400C)
end_define

begin_comment
comment|// (MCI) MCI SD Card Register
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_MR
value|((AT91_REG *) 	0xFFFB4004)
end_define

begin_comment
comment|// (MCI) MCI Mode Register
end_comment

begin_comment
comment|// ========== Register definition for UDP peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_ISR
value|((AT91_REG *) 	0xFFFB001C)
end_define

begin_comment
comment|// (UDP) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_IDR
value|((AT91_REG *) 	0xFFFB0014)
end_define

begin_comment
comment|// (UDP) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_GLBSTATE
value|((AT91_REG *) 	0xFFFB0004)
end_define

begin_comment
comment|// (UDP) Global State Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FDR
value|((AT91_REG *) 	0xFFFB0050)
end_define

begin_comment
comment|// (UDP) Endpoint FIFO Data Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_CSR
value|((AT91_REG *) 	0xFFFB0030)
end_define

begin_comment
comment|// (UDP) Endpoint Control and Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_RSTEP
value|((AT91_REG *) 	0xFFFB0028)
end_define

begin_comment
comment|// (UDP) Reset Endpoint Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_ICR
value|((AT91_REG *) 	0xFFFB0020)
end_define

begin_comment
comment|// (UDP) Interrupt Clear Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_IMR
value|((AT91_REG *) 	0xFFFB0018)
end_define

begin_comment
comment|// (UDP) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_IER
value|((AT91_REG *) 	0xFFFB0010)
end_define

begin_comment
comment|// (UDP) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_FADDR
value|((AT91_REG *) 	0xFFFB0008)
end_define

begin_comment
comment|// (UDP) Function Address Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UDP_NUM
value|((AT91_REG *) 	0xFFFB0000)
end_define

begin_comment
comment|// (UDP) Frame Number Register
end_comment

begin_comment
comment|// ========== Register definition for TC5 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_CMR
value|((AT91_REG *) 	0xFFFA4084)
end_define

begin_comment
comment|// (TC5) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_IDR
value|((AT91_REG *) 	0xFFFA40A8)
end_define

begin_comment
comment|// (TC5) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_SR
value|((AT91_REG *) 	0xFFFA40A0)
end_define

begin_comment
comment|// (TC5) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_RB
value|((AT91_REG *) 	0xFFFA4098)
end_define

begin_comment
comment|// (TC5) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_CV
value|((AT91_REG *) 	0xFFFA4090)
end_define

begin_comment
comment|// (TC5) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_CCR
value|((AT91_REG *) 	0xFFFA4080)
end_define

begin_comment
comment|// (TC5) Channel Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_IMR
value|((AT91_REG *) 	0xFFFA40AC)
end_define

begin_comment
comment|// (TC5) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_IER
value|((AT91_REG *) 	0xFFFA40A4)
end_define

begin_comment
comment|// (TC5) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_RC
value|((AT91_REG *) 	0xFFFA409C)
end_define

begin_comment
comment|// (TC5) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC5_RA
value|((AT91_REG *) 	0xFFFA4094)
end_define

begin_comment
comment|// (TC5) Register A
end_comment

begin_comment
comment|// ========== Register definition for TC4 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_IMR
value|((AT91_REG *) 	0xFFFA406C)
end_define

begin_comment
comment|// (TC4) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_IER
value|((AT91_REG *) 	0xFFFA4064)
end_define

begin_comment
comment|// (TC4) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_RC
value|((AT91_REG *) 	0xFFFA405C)
end_define

begin_comment
comment|// (TC4) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_RA
value|((AT91_REG *) 	0xFFFA4054)
end_define

begin_comment
comment|// (TC4) Register A
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_CMR
value|((AT91_REG *) 	0xFFFA4044)
end_define

begin_comment
comment|// (TC4) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_IDR
value|((AT91_REG *) 	0xFFFA4068)
end_define

begin_comment
comment|// (TC4) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_SR
value|((AT91_REG *) 	0xFFFA4060)
end_define

begin_comment
comment|// (TC4) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_RB
value|((AT91_REG *) 	0xFFFA4058)
end_define

begin_comment
comment|// (TC4) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_CV
value|((AT91_REG *) 	0xFFFA4050)
end_define

begin_comment
comment|// (TC4) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC4_CCR
value|((AT91_REG *) 	0xFFFA4040)
end_define

begin_comment
comment|// (TC4) Channel Control Register
end_comment

begin_comment
comment|// ========== Register definition for TC3 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_IMR
value|((AT91_REG *) 	0xFFFA402C)
end_define

begin_comment
comment|// (TC3) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_CV
value|((AT91_REG *) 	0xFFFA4010)
end_define

begin_comment
comment|// (TC3) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_CCR
value|((AT91_REG *) 	0xFFFA4000)
end_define

begin_comment
comment|// (TC3) Channel Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_IER
value|((AT91_REG *) 	0xFFFA4024)
end_define

begin_comment
comment|// (TC3) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_CMR
value|((AT91_REG *) 	0xFFFA4004)
end_define

begin_comment
comment|// (TC3) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_RA
value|((AT91_REG *) 	0xFFFA4014)
end_define

begin_comment
comment|// (TC3) Register A
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_RC
value|((AT91_REG *) 	0xFFFA401C)
end_define

begin_comment
comment|// (TC3) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_IDR
value|((AT91_REG *) 	0xFFFA4028)
end_define

begin_comment
comment|// (TC3) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_RB
value|((AT91_REG *) 	0xFFFA4018)
end_define

begin_comment
comment|// (TC3) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC3_SR
value|((AT91_REG *) 	0xFFFA4020)
end_define

begin_comment
comment|// (TC3) Status Register
end_comment

begin_comment
comment|// ========== Register definition for TCB1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB1_BCR
value|((AT91_REG *) 	0xFFFA4140)
end_define

begin_comment
comment|// (TCB1) TC Block Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB1_BMR
value|((AT91_REG *) 	0xFFFA4144)
end_define

begin_comment
comment|// (TCB1) TC Block Mode Register
end_comment

begin_comment
comment|// ========== Register definition for TC2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_IMR
value|((AT91_REG *) 	0xFFFA00AC)
end_define

begin_comment
comment|// (TC2) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_IER
value|((AT91_REG *) 	0xFFFA00A4)
end_define

begin_comment
comment|// (TC2) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_RC
value|((AT91_REG *) 	0xFFFA009C)
end_define

begin_comment
comment|// (TC2) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_RA
value|((AT91_REG *) 	0xFFFA0094)
end_define

begin_comment
comment|// (TC2) Register A
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_CMR
value|((AT91_REG *) 	0xFFFA0084)
end_define

begin_comment
comment|// (TC2) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_IDR
value|((AT91_REG *) 	0xFFFA00A8)
end_define

begin_comment
comment|// (TC2) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_SR
value|((AT91_REG *) 	0xFFFA00A0)
end_define

begin_comment
comment|// (TC2) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_RB
value|((AT91_REG *) 	0xFFFA0098)
end_define

begin_comment
comment|// (TC2) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_CV
value|((AT91_REG *) 	0xFFFA0090)
end_define

begin_comment
comment|// (TC2) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC2_CCR
value|((AT91_REG *) 	0xFFFA0080)
end_define

begin_comment
comment|// (TC2) Channel Control Register
end_comment

begin_comment
comment|// ========== Register definition for TC1 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_IMR
value|((AT91_REG *) 	0xFFFA006C)
end_define

begin_comment
comment|// (TC1) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_IER
value|((AT91_REG *) 	0xFFFA0064)
end_define

begin_comment
comment|// (TC1) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_RC
value|((AT91_REG *) 	0xFFFA005C)
end_define

begin_comment
comment|// (TC1) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_RA
value|((AT91_REG *) 	0xFFFA0054)
end_define

begin_comment
comment|// (TC1) Register A
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_CMR
value|((AT91_REG *) 	0xFFFA0044)
end_define

begin_comment
comment|// (TC1) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_IDR
value|((AT91_REG *) 	0xFFFA0068)
end_define

begin_comment
comment|// (TC1) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_SR
value|((AT91_REG *) 	0xFFFA0060)
end_define

begin_comment
comment|// (TC1) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_RB
value|((AT91_REG *) 	0xFFFA0058)
end_define

begin_comment
comment|// (TC1) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_CV
value|((AT91_REG *) 	0xFFFA0050)
end_define

begin_comment
comment|// (TC1) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC1_CCR
value|((AT91_REG *) 	0xFFFA0040)
end_define

begin_comment
comment|// (TC1) Channel Control Register
end_comment

begin_comment
comment|// ========== Register definition for TC0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_IMR
value|((AT91_REG *) 	0xFFFA002C)
end_define

begin_comment
comment|// (TC0) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_IER
value|((AT91_REG *) 	0xFFFA0024)
end_define

begin_comment
comment|// (TC0) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_RC
value|((AT91_REG *) 	0xFFFA001C)
end_define

begin_comment
comment|// (TC0) Register C
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_RA
value|((AT91_REG *) 	0xFFFA0014)
end_define

begin_comment
comment|// (TC0) Register A
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_CMR
value|((AT91_REG *) 	0xFFFA0004)
end_define

begin_comment
comment|// (TC0) Channel Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_IDR
value|((AT91_REG *) 	0xFFFA0028)
end_define

begin_comment
comment|// (TC0) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_SR
value|((AT91_REG *) 	0xFFFA0020)
end_define

begin_comment
comment|// (TC0) Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_RB
value|((AT91_REG *) 	0xFFFA0018)
end_define

begin_comment
comment|// (TC0) Register B
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_CV
value|((AT91_REG *) 	0xFFFA0010)
end_define

begin_comment
comment|// (TC0) Counter Value
end_comment

begin_define
define|#
directive|define
name|AT91C_TC0_CCR
value|((AT91_REG *) 	0xFFFA0000)
end_define

begin_comment
comment|// (TC0) Channel Control Register
end_comment

begin_comment
comment|// ========== Register definition for TCB0 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB0_BMR
value|((AT91_REG *) 	0xFFFA00C4)
end_define

begin_comment
comment|// (TCB0) TC Block Mode Register
end_comment

begin_define
define|#
directive|define
name|AT91C_TCB0_BCR
value|((AT91_REG *) 	0xFFFA00C0)
end_define

begin_comment
comment|// (TCB0) TC Block Control Register
end_comment

begin_comment
comment|// ========== Register definition for UHP peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcRhDescriptorA
value|((AT91_REG *) 	0x00300048)
end_define

begin_comment
comment|// (UHP) Root Hub characteristics A
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcRhPortStatus
value|((AT91_REG *) 	0x00300054)
end_define

begin_comment
comment|// (UHP) Root Hub Port Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcRhDescriptorB
value|((AT91_REG *) 	0x0030004C)
end_define

begin_comment
comment|// (UHP) Root Hub characteristics B
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcControl
value|((AT91_REG *) 	0x00300004)
end_define

begin_comment
comment|// (UHP) Operating modes for the Host Controller
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcInterruptStatus
value|((AT91_REG *) 	0x0030000C)
end_define

begin_comment
comment|// (UHP) Interrupt Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcRhStatus
value|((AT91_REG *) 	0x00300050)
end_define

begin_comment
comment|// (UHP) Root Hub Status register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcRevision
value|((AT91_REG *) 	0x00300000)
end_define

begin_comment
comment|// (UHP) Revision
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcCommandStatus
value|((AT91_REG *) 	0x00300008)
end_define

begin_comment
comment|// (UHP) Command& status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcInterruptEnable
value|((AT91_REG *) 	0x00300010)
end_define

begin_comment
comment|// (UHP) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcHCCA
value|((AT91_REG *) 	0x00300018)
end_define

begin_comment
comment|// (UHP) Pointer to the Host Controller Communication Area
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcControlHeadED
value|((AT91_REG *) 	0x00300020)
end_define

begin_comment
comment|// (UHP) First Endpoint Descriptor of the Control list
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcInterruptDisable
value|((AT91_REG *) 	0x00300014)
end_define

begin_comment
comment|// (UHP) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcPeriodCurrentED
value|((AT91_REG *) 	0x0030001C)
end_define

begin_comment
comment|// (UHP) Current Isochronous or Interrupt Endpoint Descriptor
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcControlCurrentED
value|((AT91_REG *) 	0x00300024)
end_define

begin_comment
comment|// (UHP) Endpoint Control and Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcBulkCurrentED
value|((AT91_REG *) 	0x0030002C)
end_define

begin_comment
comment|// (UHP) Current endpoint of the Bulk list
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcFmInterval
value|((AT91_REG *) 	0x00300034)
end_define

begin_comment
comment|// (UHP) Bit time between 2 consecutive SOFs
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcBulkHeadED
value|((AT91_REG *) 	0x00300028)
end_define

begin_comment
comment|// (UHP) First endpoint register of the Bulk list
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcBulkDoneHead
value|((AT91_REG *) 	0x00300030)
end_define

begin_comment
comment|// (UHP) Last completed transfer descriptor
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcFmRemaining
value|((AT91_REG *) 	0x00300038)
end_define

begin_comment
comment|// (UHP) Bit time remaining in the current Frame
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcPeriodicStart
value|((AT91_REG *) 	0x00300040)
end_define

begin_comment
comment|// (UHP) Periodic Start
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcLSThreshold
value|((AT91_REG *) 	0x00300044)
end_define

begin_comment
comment|// (UHP) LS Threshold
end_comment

begin_define
define|#
directive|define
name|AT91C_UHP_HcFmNumber
value|((AT91_REG *) 	0x0030003C)
end_define

begin_comment
comment|// (UHP) Frame number
end_comment

begin_comment
comment|// ========== Register definition for EMAC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RSR
value|((AT91_REG *) 	0xFFFBC020)
end_define

begin_comment
comment|// (EMAC) Receive Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_MAN
value|((AT91_REG *) 	0xFFFBC034)
end_define

begin_comment
comment|// (EMAC) PHY Maintenance Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_HSH
value|((AT91_REG *) 	0xFFFBC090)
end_define

begin_comment
comment|// (EMAC) Hash Address High[63:32]
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_MCOL
value|((AT91_REG *) 	0xFFFBC048)
end_define

begin_comment
comment|// (EMAC) Multiple Collision Frame Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_IER
value|((AT91_REG *) 	0xFFFBC028)
end_define

begin_comment
comment|// (EMAC) Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA2H
value|((AT91_REG *) 	0xFFFBC0A4)
end_define

begin_comment
comment|// (EMAC) Specific Address 2 High, Last 2 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_HSL
value|((AT91_REG *) 	0xFFFBC094)
end_define

begin_comment
comment|// (EMAC) Hash Address Low[31:0]
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_LCOL
value|((AT91_REG *) 	0xFFFBC05C)
end_define

begin_comment
comment|// (EMAC) Late Collision Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_OK
value|((AT91_REG *) 	0xFFFBC04C)
end_define

begin_comment
comment|// (EMAC) Frames Received OK Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CFG
value|((AT91_REG *) 	0xFFFBC004)
end_define

begin_comment
comment|// (EMAC) Network Configuration Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA3L
value|((AT91_REG *) 	0xFFFBC0A8)
end_define

begin_comment
comment|// (EMAC) Specific Address 3 Low, First 4 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SEQE
value|((AT91_REG *) 	0xFFFBC050)
end_define

begin_comment
comment|// (EMAC) Frame Check Sequence Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_ECOL
value|((AT91_REG *) 	0xFFFBC060)
end_define

begin_comment
comment|// (EMAC) Excessive Collision Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_ELR
value|((AT91_REG *) 	0xFFFBC070)
end_define

begin_comment
comment|// (EMAC) Excessive Length Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SR
value|((AT91_REG *) 	0xFFFBC008)
end_define

begin_comment
comment|// (EMAC) Network Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RBQP
value|((AT91_REG *) 	0xFFFBC018)
end_define

begin_comment
comment|// (EMAC) Receive Buffer Queue Pointer
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CSE
value|((AT91_REG *) 	0xFFFBC064)
end_define

begin_comment
comment|// (EMAC) Carrier Sense Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_RJB
value|((AT91_REG *) 	0xFFFBC074)
end_define

begin_comment
comment|// (EMAC) Receive Jabber Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_USF
value|((AT91_REG *) 	0xFFFBC078)
end_define

begin_comment
comment|// (EMAC) Undersize Frame Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_IDR
value|((AT91_REG *) 	0xFFFBC02C)
end_define

begin_comment
comment|// (EMAC) Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA1L
value|((AT91_REG *) 	0xFFFBC098)
end_define

begin_comment
comment|// (EMAC) Specific Address 1 Low, First 4 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_IMR
value|((AT91_REG *) 	0xFFFBC030)
end_define

begin_comment
comment|// (EMAC) Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_FRA
value|((AT91_REG *) 	0xFFFBC040)
end_define

begin_comment
comment|// (EMAC) Frames Transmitted OK Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA3H
value|((AT91_REG *) 	0xFFFBC0AC)
end_define

begin_comment
comment|// (EMAC) Specific Address 3 High, Last 2 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA1H
value|((AT91_REG *) 	0xFFFBC09C)
end_define

begin_comment
comment|// (EMAC) Specific Address 1 High, Last 2 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SCOL
value|((AT91_REG *) 	0xFFFBC044)
end_define

begin_comment
comment|// (EMAC) Single Collision Frame Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_ALE
value|((AT91_REG *) 	0xFFFBC054)
end_define

begin_comment
comment|// (EMAC) Alignment Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TAR
value|((AT91_REG *) 	0xFFFBC00C)
end_define

begin_comment
comment|// (EMAC) Transmit Address Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA4L
value|((AT91_REG *) 	0xFFFBC0B0)
end_define

begin_comment
comment|// (EMAC) Specific Address 4 Low, First 4 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA2L
value|((AT91_REG *) 	0xFFFBC0A0)
end_define

begin_comment
comment|// (EMAC) Specific Address 2 Low, First 4 bytes
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TUE
value|((AT91_REG *) 	0xFFFBC068)
end_define

begin_comment
comment|// (EMAC) Transmit Underrun Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_DTE
value|((AT91_REG *) 	0xFFFBC058)
end_define

begin_comment
comment|// (EMAC) Deferred Transmission Frame Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TCR
value|((AT91_REG *) 	0xFFFBC010)
end_define

begin_comment
comment|// (EMAC) Transmit Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CTL
value|((AT91_REG *) 	0xFFFBC000)
end_define

begin_comment
comment|// (EMAC) Network Control Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SA4H
value|((AT91_REG *) 	0xFFFBC0B4)
end_define

begin_comment
comment|// (EMAC) Specific Address 4 High, Last 2 bytesr
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_CDE
value|((AT91_REG *) 	0xFFFBC06C)
end_define

begin_comment
comment|// (EMAC) Code Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_SQEE
value|((AT91_REG *) 	0xFFFBC07C)
end_define

begin_comment
comment|// (EMAC) SQE Test Error Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_TSR
value|((AT91_REG *) 	0xFFFBC014)
end_define

begin_comment
comment|// (EMAC) Transmit Status Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EMAC_DRFC
value|((AT91_REG *) 	0xFFFBC080)
end_define

begin_comment
comment|// (EMAC) Discarded RX Frame Register
end_comment

begin_comment
comment|// ========== Register definition for EBI peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CFGR
value|((AT91_REG *) 	0xFFFFFF64)
end_define

begin_comment
comment|// (EBI) Configuration Register
end_comment

begin_define
define|#
directive|define
name|AT91C_EBI_CSA
value|((AT91_REG *) 	0xFFFFFF60)
end_define

begin_comment
comment|// (EBI) Chip Select Assignment Register
end_comment

begin_comment
comment|// ========== Register definition for SMC2 peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SMC2_CSR
value|((AT91_REG *) 	0xFFFFFF70)
end_define

begin_comment
comment|// (SMC2) SMC2 Chip Select Register
end_comment

begin_comment
comment|// ========== Register definition for SDRC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_IMR
value|((AT91_REG *) 	0xFFFFFFAC)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_IER
value|((AT91_REG *) 	0xFFFFFFA4)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Interrupt Enable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_SRR
value|((AT91_REG *) 	0xFFFFFF9C)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Self Refresh Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_TR
value|((AT91_REG *) 	0xFFFFFF94)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Refresh Timer Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_ISR
value|((AT91_REG *) 	0xFFFFFFB0)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Interrupt Mask Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_IDR
value|((AT91_REG *) 	0xFFFFFFA8)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Interrupt Disable Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_LPR
value|((AT91_REG *) 	0xFFFFFFA0)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Low Power Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_CR
value|((AT91_REG *) 	0xFFFFFF98)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Configuration Register
end_comment

begin_define
define|#
directive|define
name|AT91C_SDRC_MR
value|((AT91_REG *) 	0xFFFFFF90)
end_define

begin_comment
comment|// (SDRC) SDRAM Controller Mode Register
end_comment

begin_comment
comment|// ========== Register definition for BFC peripheral ==========
end_comment

begin_define
define|#
directive|define
name|AT91C_BFC_MR
value|((AT91_REG *) 	0xFFFFFFC0)
end_define

begin_comment
comment|// (BFC) BFC Mode Register
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               PIO DEFINITIONS FOR AT91RM9200
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PA0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MISO
value|((unsigned int) AT91C_PIO_PA0)
end_define

begin_comment
comment|//  SPI Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_PCK3
value|((unsigned int) AT91C_PIO_PA0)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PA1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MOSI
value|((unsigned int) AT91C_PIO_PA1)
end_define

begin_comment
comment|//  SPI Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_PCK0
value|((unsigned int) AT91C_PIO_PA1)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PA10
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_ETX1
value|((unsigned int) AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_MCDB1
value|((unsigned int) AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Multimedia Card B Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PA11
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_ECRS_ECRSDV
value|((unsigned int) AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Ethernet MAC Carrier Sense/Carrier Sense and Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_MCDB2
value|((unsigned int) AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Multimedia Card B Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PA12
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_ERX0
value|((unsigned int) AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_MCDB3
value|((unsigned int) AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Multimedia Card B Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PA13
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_ERX1
value|((unsigned int) AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_TCLK0
value|((unsigned int) AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Timer Counter 0 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PA14
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_ERXER
value|((unsigned int) AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Ethernet MAC Receive Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_TCLK1
value|((unsigned int) AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Timer Counter 1 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PA15
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_EMDC
value|((unsigned int) AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_TCLK2
value|((unsigned int) AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Timer Counter 2 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PA16
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_EMDIO
value|((unsigned int) AT91C_PIO_PA16)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Input/Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_IRQ6
value|((unsigned int) AT91C_PIO_PA16)
end_define

begin_comment
comment|//  AIC Interrupt input 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PA17
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TXD0
value|((unsigned int) AT91C_PIO_PA17)
end_define

begin_comment
comment|//  USART 0 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TIOA0
value|((unsigned int) AT91C_PIO_PA17)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PA18
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_RXD0
value|((unsigned int) AT91C_PIO_PA18)
end_define

begin_comment
comment|//  USART 0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_TIOB0
value|((unsigned int) AT91C_PIO_PA18)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PA19
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_SCK0
value|((unsigned int) AT91C_PIO_PA19)
end_define

begin_comment
comment|//  USART 0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_TIOA1
value|((unsigned int) AT91C_PIO_PA19)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PA2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_SPCK
value|((unsigned int) AT91C_PIO_PA2)
end_define

begin_comment
comment|//  SPI Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_IRQ4
value|((unsigned int) AT91C_PIO_PA2)
end_define

begin_comment
comment|//  AIC Interrupt Input 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PA20
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_CTS0
value|((unsigned int) AT91C_PIO_PA20)
end_define

begin_comment
comment|//  USART 0 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_TIOB1
value|((unsigned int) AT91C_PIO_PA20)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PA21
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_RTS0
value|((unsigned int) AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_TIOA2
value|((unsigned int) AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PA22
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_RXD2
value|((unsigned int) AT91C_PIO_PA22)
end_define

begin_comment
comment|//  USART 2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_TIOB2
value|((unsigned int) AT91C_PIO_PA22)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PA23
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_TXD2
value|((unsigned int) AT91C_PIO_PA23)
end_define

begin_comment
comment|//  USART 2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_IRQ3
value|((unsigned int) AT91C_PIO_PA23)
end_define

begin_comment
comment|//  Interrupt input 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PA24
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_SCK2
value|((unsigned int) AT91C_PIO_PA24)
end_define

begin_comment
comment|//  USART2 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_PCK1
value|((unsigned int) AT91C_PIO_PA24)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PA25
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_TWD
value|((unsigned int) AT91C_PIO_PA25)
end_define

begin_comment
comment|//  TWI Two-wire Serial Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_IRQ2
value|((unsigned int) AT91C_PIO_PA25)
end_define

begin_comment
comment|//  Interrupt input 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PA26
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_TWCK
value|((unsigned int) AT91C_PIO_PA26)
end_define

begin_comment
comment|//  TWI Two-wire Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_IRQ1
value|((unsigned int) AT91C_PIO_PA26)
end_define

begin_comment
comment|//  Interrupt input 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PA27
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_MCCK
value|((unsigned int) AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Multimedia Card Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_TCLK3
value|((unsigned int) AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Timer Counter 3 External Clock Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PA28
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_MCCDA
value|((unsigned int) AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Multimedia Card A Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_TCLK4
value|((unsigned int) AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Timer Counter 4 external Clock Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PA29
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_MCDA0
value|((unsigned int) AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Multimedia Card A Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_TCLK5
value|((unsigned int) AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Timer Counter 5 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PA3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_NPCS0
value|((unsigned int) AT91C_PIO_PA3)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_IRQ5
value|((unsigned int) AT91C_PIO_PA3)
end_define

begin_comment
comment|//  AIC Interrupt Input 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PA30
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_DRXD
value|((unsigned int) AT91C_PIO_PA30)
end_define

begin_comment
comment|//  DBGU Debug Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_CTS2
value|((unsigned int) AT91C_PIO_PA30)
end_define

begin_comment
comment|//  Usart 2 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PA31
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_DTXD
value|((unsigned int) AT91C_PIO_PA31)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_RTS2
value|((unsigned int) AT91C_PIO_PA31)
end_define

begin_comment
comment|//  USART 2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PA4
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_NPCS1
value|((unsigned int) AT91C_PIO_PA4)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_PCK1
value|((unsigned int) AT91C_PIO_PA4)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PA5
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_NPCS2
value|((unsigned int) AT91C_PIO_PA5)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_TXD3
value|((unsigned int) AT91C_PIO_PA5)
end_define

begin_comment
comment|//  USART 3 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PA6
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_NPCS3
value|((unsigned int) AT91C_PIO_PA6)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_RXD3
value|((unsigned int) AT91C_PIO_PA6)
end_define

begin_comment
comment|//  USART 3 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PA7
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_ETXCK_EREFCK
value|((unsigned int) AT91C_PIO_PA7)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Clock/Reference Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_PCK2
value|((unsigned int) AT91C_PIO_PA7)
end_define

begin_comment
comment|//  PMC Programmable Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PA8
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_ETXEN
value|((unsigned int) AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_MCCDB
value|((unsigned int) AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Multimedia Card B Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PA9
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_ETX0
value|((unsigned int) AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_MCDB0
value|((unsigned int) AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Multimedia Card B Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PB0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_TF0
value|((unsigned int) AT91C_PIO_PB0)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_TIOB3
value|((unsigned int) AT91C_PIO_PB0)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PB1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_TK0
value|((unsigned int) AT91C_PIO_PB1)
end_define

begin_comment
comment|//  SSC Transmit Clock 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_CTS3
value|((unsigned int) AT91C_PIO_PB1)
end_define

begin_comment
comment|//  USART 3 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PB10
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_RK1
value|((unsigned int) AT91C_PIO_PB10)
end_define

begin_comment
comment|//  SSC Receive Clock 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_TIOA5
value|((unsigned int) AT91C_PIO_PB10)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PB11
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_RF1
value|((unsigned int) AT91C_PIO_PB11)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_TIOB5
value|((unsigned int) AT91C_PIO_PB11)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PB12
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_TF2
value|((unsigned int) AT91C_PIO_PB12)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_ETX2
value|((unsigned int) AT91C_PIO_PB12)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PB13
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_TK2
value|((unsigned int) AT91C_PIO_PB13)
end_define

begin_comment
comment|//  SSC Transmit Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_ETX3
value|((unsigned int) AT91C_PIO_PB13)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PB14
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_TD2
value|((unsigned int) AT91C_PIO_PB14)
end_define

begin_comment
comment|//  SSC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_ETXER
value|((unsigned int) AT91C_PIO_PB14)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PB15
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_RD2
value|((unsigned int) AT91C_PIO_PB15)
end_define

begin_comment
comment|//  SSC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_ERX2
value|((unsigned int) AT91C_PIO_PB15)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PB16
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_RK2
value|((unsigned int) AT91C_PIO_PB16)
end_define

begin_comment
comment|//  SSC Receive Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_ERX3
value|((unsigned int) AT91C_PIO_PB16)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PB17
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_RF2
value|((unsigned int) AT91C_PIO_PB17)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_ERXDV
value|((unsigned int) AT91C_PIO_PB17)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PB18
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_RI1
value|((unsigned int) AT91C_PIO_PB18)
end_define

begin_comment
comment|//  USART 1 Ring Indicator
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_ECOL
value|((unsigned int) AT91C_PIO_PB18)
end_define

begin_comment
comment|//  Ethernet MAC Collision Detected
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PB19
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_DTR1
value|((unsigned int) AT91C_PIO_PB19)
end_define

begin_comment
comment|//  USART 1 Data Terminal ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_ERXCK
value|((unsigned int) AT91C_PIO_PB19)
end_define

begin_comment
comment|//  Ethernet MAC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PB2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_TD0
value|((unsigned int) AT91C_PIO_PB2)
end_define

begin_comment
comment|//  SSC Transmit data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_SCK3
value|((unsigned int) AT91C_PIO_PB2)
end_define

begin_comment
comment|//  USART 3 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PB20
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_TXD1
value|((unsigned int) AT91C_PIO_PB20)
end_define

begin_comment
comment|//  USART 1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PB21
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_RXD1
value|((unsigned int) AT91C_PIO_PB21)
end_define

begin_comment
comment|//  USART 1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PB22
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_SCK1
value|((unsigned int) AT91C_PIO_PB22)
end_define

begin_comment
comment|//  USART1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PB23
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_DCD1
value|((unsigned int) AT91C_PIO_PB23)
end_define

begin_comment
comment|//  USART 1 Data Carrier Detect
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PB24
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_CTS1
value|((unsigned int) AT91C_PIO_PB24)
end_define

begin_comment
comment|//  USART 1 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PB25
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_DSR1
value|((unsigned int) AT91C_PIO_PB25)
end_define

begin_comment
comment|//  USART 1 Data Set ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_EF100
value|((unsigned int) AT91C_PIO_PB25)
end_define

begin_comment
comment|//  Ethernet MAC Force 100 Mbits/sec
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PB26
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_RTS1
value|((unsigned int) AT91C_PIO_PB26)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PB27
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_PCK0
value|((unsigned int) AT91C_PIO_PB27)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PB28
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_FIQ
value|((unsigned int) AT91C_PIO_PB28)
end_define

begin_comment
comment|//  AIC Fast Interrupt Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PB29
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_IRQ0
value|((unsigned int) AT91C_PIO_PB29)
end_define

begin_comment
comment|//  Interrupt input 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PB3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_RD0
value|((unsigned int) AT91C_PIO_PB3)
end_define

begin_comment
comment|//  SSC Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_MCDA1
value|((unsigned int) AT91C_PIO_PB3)
end_define

begin_comment
comment|//  Multimedia Card A Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PB4
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_RK0
value|((unsigned int) AT91C_PIO_PB4)
end_define

begin_comment
comment|//  SSC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_MCDA2
value|((unsigned int) AT91C_PIO_PB4)
end_define

begin_comment
comment|//  Multimedia Card A Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PB5
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_RF0
value|((unsigned int) AT91C_PIO_PB5)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_MCDA3
value|((unsigned int) AT91C_PIO_PB5)
end_define

begin_comment
comment|//  Multimedia Card A Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PB6
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TF1
value|((unsigned int) AT91C_PIO_PB6)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TIOA3
value|((unsigned int) AT91C_PIO_PB6)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PB7
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_TK1
value|((unsigned int) AT91C_PIO_PB7)
end_define

begin_comment
comment|//  SSC Transmit Clock 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_TIOB3
value|((unsigned int) AT91C_PIO_PB7)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PB8
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TD1
value|((unsigned int) AT91C_PIO_PB8)
end_define

begin_comment
comment|//  SSC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TIOA4
value|((unsigned int) AT91C_PIO_PB8)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PB9
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_RD1
value|((unsigned int) AT91C_PIO_PB9)
end_define

begin_comment
comment|//  SSC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_TIOB4
value|((unsigned int) AT91C_PIO_PB9)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PC0
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_BFCK
value|((unsigned int) AT91C_PIO_PC0)
end_define

begin_comment
comment|//  Burst Flash Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PC1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_BFRDY_SMOE
value|((unsigned int) AT91C_PIO_PC1)
end_define

begin_comment
comment|//  Burst Flash Ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PC10
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_NCS4_CFCS
value|((unsigned int) AT91C_PIO_PC10)
end_define

begin_comment
comment|//  Compact Flash Chip Select
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PC11
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_NCS5_CFCE1
value|((unsigned int) AT91C_PIO_PC11)
end_define

begin_comment
comment|//  Chip Select 5 / Compact Flash Chip Enable 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PC12
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_NCS6_CFCE2
value|((unsigned int) AT91C_PIO_PC12)
end_define

begin_comment
comment|//  Chip Select 6 / Compact Flash Chip Enable 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PC13
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_NCS7
value|((unsigned int) AT91C_PIO_PC13)
end_define

begin_comment
comment|//  Chip Select 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PC14
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PC15
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PC16
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_D16
value|((unsigned int) AT91C_PIO_PC16)
end_define

begin_comment
comment|//  Data Bus [16]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PC17
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_D17
value|((unsigned int) AT91C_PIO_PC17)
end_define

begin_comment
comment|//  Data Bus [17]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PC18
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_D18
value|((unsigned int) AT91C_PIO_PC18)
end_define

begin_comment
comment|//  Data Bus [18]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PC19
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_D19
value|((unsigned int) AT91C_PIO_PC19)
end_define

begin_comment
comment|//  Data Bus [19]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PC2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_BFAVD
value|((unsigned int) AT91C_PIO_PC2)
end_define

begin_comment
comment|//  Burst Flash Address Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PC20
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_D20
value|((unsigned int) AT91C_PIO_PC20)
end_define

begin_comment
comment|//  Data Bus [20]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PC21
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_D21
value|((unsigned int) AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Data Bus [21]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PC22
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_D22
value|((unsigned int) AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Data Bus [22]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PC23
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_D23
value|((unsigned int) AT91C_PIO_PC23)
end_define

begin_comment
comment|//  Data Bus [23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PC24
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_D24
value|((unsigned int) AT91C_PIO_PC24)
end_define

begin_comment
comment|//  Data Bus [24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PC25
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_D25
value|((unsigned int) AT91C_PIO_PC25)
end_define

begin_comment
comment|//  Data Bus [25]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PC26
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_D26
value|((unsigned int) AT91C_PIO_PC26)
end_define

begin_comment
comment|//  Data Bus [26]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PC27
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_D27
value|((unsigned int) AT91C_PIO_PC27)
end_define

begin_comment
comment|//  Data Bus [27]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PC28
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_D28
value|((unsigned int) AT91C_PIO_PC28)
end_define

begin_comment
comment|//  Data Bus [28]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PC29
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_D29
value|((unsigned int) AT91C_PIO_PC29)
end_define

begin_comment
comment|//  Data Bus [29]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PC3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_BFBAA_SMWE
value|((unsigned int) AT91C_PIO_PC3)
end_define

begin_comment
comment|//  Burst Flash Address Advance / SmartMedia Write Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PC30
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_D30
value|((unsigned int) AT91C_PIO_PC30)
end_define

begin_comment
comment|//  Data Bus [30]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PC31
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_D31
value|((unsigned int) AT91C_PIO_PC31)
end_define

begin_comment
comment|//  Data Bus [31]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PC4
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_BFOE
value|((unsigned int) AT91C_PIO_PC4)
end_define

begin_comment
comment|//  Burst Flash Output Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PC5
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_BFWE
value|((unsigned int) AT91C_PIO_PC5)
end_define

begin_comment
comment|//  Burst Flash Write Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PC6
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_NWAIT
value|((unsigned int) AT91C_PIO_PC6)
end_define

begin_comment
comment|//  NWAIT
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PC7
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_A23
value|((unsigned int) AT91C_PIO_PC7)
end_define

begin_comment
comment|//  Address Bus[23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PC8
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_A24
value|((unsigned int) AT91C_PIO_PC8)
end_define

begin_comment
comment|//  Address Bus[24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PC9
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_A25_CFRNW
value|((unsigned int) AT91C_PIO_PC9)
end_define

begin_comment
comment|//  Address Bus[25] /  Compact Flash Read Not Write
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PD0
end_comment

begin_define
define|#
directive|define
name|AT91C_PD0_ETX0
value|((unsigned int) AT91C_PIO_PD0)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PD1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD1_ETX1
value|((unsigned int) AT91C_PIO_PD1)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PD10
end_comment

begin_define
define|#
directive|define
name|AT91C_PD10_PCK3
value|((unsigned int) AT91C_PIO_PD10)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD10_TPS1
value|((unsigned int) AT91C_PIO_PD10)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PD11
end_comment

begin_define
define|#
directive|define
name|AT91C_PD11_
value|((unsigned int) AT91C_PIO_PD11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD11_TPS2
value|((unsigned int) AT91C_PIO_PD11)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PD12
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_
value|((unsigned int) AT91C_PIO_PD12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_TPK0
value|((unsigned int) AT91C_PIO_PD12)
end_define

begin_comment
comment|//  ETM Trace Packet 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PD13
end_comment

begin_define
define|#
directive|define
name|AT91C_PD13_
value|((unsigned int) AT91C_PIO_PD13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD13_TPK1
value|((unsigned int) AT91C_PIO_PD13)
end_define

begin_comment
comment|//  ETM Trace Packet 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PD14
end_comment

begin_define
define|#
directive|define
name|AT91C_PD14_
value|((unsigned int) AT91C_PIO_PD14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD14_TPK2
value|((unsigned int) AT91C_PIO_PD14)
end_define

begin_comment
comment|//  ETM Trace Packet 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PD15
end_comment

begin_define
define|#
directive|define
name|AT91C_PD15_TD0
value|((unsigned int) AT91C_PIO_PD15)
end_define

begin_comment
comment|//  SSC Transmit data
end_comment

begin_define
define|#
directive|define
name|AT91C_PD15_TPK3
value|((unsigned int) AT91C_PIO_PD15)
end_define

begin_comment
comment|//  ETM Trace Packet 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PD16
end_comment

begin_define
define|#
directive|define
name|AT91C_PD16_TD1
value|((unsigned int) AT91C_PIO_PD16)
end_define

begin_comment
comment|//  SSC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD16_TPK4
value|((unsigned int) AT91C_PIO_PD16)
end_define

begin_comment
comment|//  ETM Trace Packet 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PD17
end_comment

begin_define
define|#
directive|define
name|AT91C_PD17_TD2
value|((unsigned int) AT91C_PIO_PD17)
end_define

begin_comment
comment|//  SSC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD17_TPK5
value|((unsigned int) AT91C_PIO_PD17)
end_define

begin_comment
comment|//  ETM Trace Packet 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PD18
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_NPCS1
value|((unsigned int) AT91C_PIO_PD18)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_TPK6
value|((unsigned int) AT91C_PIO_PD18)
end_define

begin_comment
comment|//  ETM Trace Packet 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PD19
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_NPCS2
value|((unsigned int) AT91C_PIO_PD19)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_TPK7
value|((unsigned int) AT91C_PIO_PD19)
end_define

begin_comment
comment|//  ETM Trace Packet 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PD2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD2_ETX2
value|((unsigned int) AT91C_PIO_PD2)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PD20
end_comment

begin_define
define|#
directive|define
name|AT91C_PD20_NPCS3
value|((unsigned int) AT91C_PIO_PD20)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD20_TPK8
value|((unsigned int) AT91C_PIO_PD20)
end_define

begin_comment
comment|//  ETM Trace Packet 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PD21
end_comment

begin_define
define|#
directive|define
name|AT91C_PD21_RTS0
value|((unsigned int) AT91C_PIO_PD21)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD21_TPK9
value|((unsigned int) AT91C_PIO_PD21)
end_define

begin_comment
comment|//  ETM Trace Packet 9
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PD22
end_comment

begin_define
define|#
directive|define
name|AT91C_PD22_RTS1
value|((unsigned int) AT91C_PIO_PD22)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD22_TPK10
value|((unsigned int) AT91C_PIO_PD22)
end_define

begin_comment
comment|//  ETM Trace Packet 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PD23
end_comment

begin_define
define|#
directive|define
name|AT91C_PD23_RTS2
value|((unsigned int) AT91C_PIO_PD23)
end_define

begin_comment
comment|//  USART 2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD23_TPK11
value|((unsigned int) AT91C_PIO_PD23)
end_define

begin_comment
comment|//  ETM Trace Packet 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PD24
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_RTS3
value|((unsigned int) AT91C_PIO_PD24)
end_define

begin_comment
comment|//  USART 3 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_TPK12
value|((unsigned int) AT91C_PIO_PD24)
end_define

begin_comment
comment|//  ETM Trace Packet 12
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PD25
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_DTR1
value|((unsigned int) AT91C_PIO_PD25)
end_define

begin_comment
comment|//  USART 1 Data Terminal ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_TPK13
value|((unsigned int) AT91C_PIO_PD25)
end_define

begin_comment
comment|//  ETM Trace Packet 13
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PD26
end_comment

begin_define
define|#
directive|define
name|AT91C_PD26_TPK14
value|((unsigned int) AT91C_PIO_PD26)
end_define

begin_comment
comment|//  ETM Trace Packet 14
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PD27
end_comment

begin_define
define|#
directive|define
name|AT91C_PD27_TPK15
value|((unsigned int) AT91C_PIO_PD27)
end_define

begin_comment
comment|//  ETM Trace Packet 15
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PD3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD3_ETX3
value|((unsigned int) AT91C_PIO_PD3)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PD4
end_comment

begin_define
define|#
directive|define
name|AT91C_PD4_ETXEN
value|((unsigned int) AT91C_PIO_PD4)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PD5
end_comment

begin_define
define|#
directive|define
name|AT91C_PD5_ETXER
value|((unsigned int) AT91C_PIO_PD5)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PD6
end_comment

begin_define
define|#
directive|define
name|AT91C_PD6_DTXD
value|((unsigned int) AT91C_PIO_PD6)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PD7
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_PCK0
value|((unsigned int) AT91C_PIO_PD7)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_TSYNC
value|((unsigned int) AT91C_PIO_PD7)
end_define

begin_comment
comment|//  ETM Synchronization signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PD8
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_PCK1
value|((unsigned int) AT91C_PIO_PD8)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_TCLK
value|((unsigned int) AT91C_PIO_PD8)
end_define

begin_comment
comment|//  ETM Trace Clock signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PD9
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_PCK2
value|((unsigned int) AT91C_PIO_PD9)
end_define

begin_comment
comment|//  PMC Programmable Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_TPS0
value|((unsigned int) AT91C_PIO_PD9)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 0
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               PERIPHERAL ID DEFINITIONS FOR AT91RM9200
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_FIQ
value|((unsigned int)  0)
end_define

begin_comment
comment|// Advanced Interrupt Controller (FIQ)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_SYS
value|((unsigned int)  1)
end_define

begin_comment
comment|// System Peripheral
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_PIOA
value|((unsigned int)  2)
end_define

begin_comment
comment|// Parallel IO Controller A
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_PIOB
value|((unsigned int)  3)
end_define

begin_comment
comment|// Parallel IO Controller B
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_PIOC
value|((unsigned int)  4)
end_define

begin_comment
comment|// Parallel IO Controller C
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_PIOD
value|((unsigned int)  5)
end_define

begin_comment
comment|// Parallel IO Controller D
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_US0
value|((unsigned int)  6)
end_define

begin_comment
comment|// USART 0
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_US1
value|((unsigned int)  7)
end_define

begin_comment
comment|// USART 1
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_US2
value|((unsigned int)  8)
end_define

begin_comment
comment|// USART 2
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_US3
value|((unsigned int)  9)
end_define

begin_comment
comment|// USART 3
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_MCI
value|((unsigned int) 10)
end_define

begin_comment
comment|// Multimedia Card Interface
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_UDP
value|((unsigned int) 11)
end_define

begin_comment
comment|// USB Device Port
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TWI
value|((unsigned int) 12)
end_define

begin_comment
comment|// Two-Wire Interface
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_SPI
value|((unsigned int) 13)
end_define

begin_comment
comment|// Serial Peripheral Interface
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_SSC0
value|((unsigned int) 14)
end_define

begin_comment
comment|// Serial Synchronous Controller 0
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_SSC1
value|((unsigned int) 15)
end_define

begin_comment
comment|// Serial Synchronous Controller 1
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_SSC2
value|((unsigned int) 16)
end_define

begin_comment
comment|// Serial Synchronous Controller 2
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC0
value|((unsigned int) 17)
end_define

begin_comment
comment|// Timer Counter 0
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC1
value|((unsigned int) 18)
end_define

begin_comment
comment|// Timer Counter 1
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC2
value|((unsigned int) 19)
end_define

begin_comment
comment|// Timer Counter 2
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC3
value|((unsigned int) 20)
end_define

begin_comment
comment|// Timer Counter 3
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC4
value|((unsigned int) 21)
end_define

begin_comment
comment|// Timer Counter 4
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_TC5
value|((unsigned int) 22)
end_define

begin_comment
comment|// Timer Counter 5
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_UHP
value|((unsigned int) 23)
end_define

begin_comment
comment|// USB Host port
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_EMAC
value|((unsigned int) 24)
end_define

begin_comment
comment|// Ethernet MAC
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ0
value|((unsigned int) 25)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ0)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ1
value|((unsigned int) 26)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ1)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ2
value|((unsigned int) 27)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ2)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ3
value|((unsigned int) 28)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ3)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ4
value|((unsigned int) 29)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ4)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ5
value|((unsigned int) 30)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ5)
end_comment

begin_define
define|#
directive|define
name|AT91C_ID_IRQ6
value|((unsigned int) 31)
end_define

begin_comment
comment|// Advanced Interrupt Controller (IRQ6)
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               BASE ADDRESS DEFINITIONS FOR AT91RM9200
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SYS
value|((AT91PS_SYS) 	0xFFFFF000)
end_define

begin_comment
comment|// (SYS) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_MC
value|((AT91PS_MC) 	0xFFFFFF00)
end_define

begin_comment
comment|// (MC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_RTC
value|((AT91PS_RTC) 	0xFFFFFE00)
end_define

begin_comment
comment|// (RTC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_ST
value|((AT91PS_ST) 	0xFFFFFD00)
end_define

begin_comment
comment|// (ST) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PMC
value|((AT91PS_PMC) 	0xFFFFFC00)
end_define

begin_comment
comment|// (PMC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_CKGR
value|((AT91PS_CKGR) 	0xFFFFFC20)
end_define

begin_comment
comment|// (CKGR) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PIOD
value|((AT91PS_PIO) 	0xFFFFFA00)
end_define

begin_comment
comment|// (PIOD) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PIOC
value|((AT91PS_PIO) 	0xFFFFF800)
end_define

begin_comment
comment|// (PIOC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PIOB
value|((AT91PS_PIO) 	0xFFFFF600)
end_define

begin_comment
comment|// (PIOB) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PIOA
value|((AT91PS_PIO) 	0xFFFFF400)
end_define

begin_comment
comment|// (PIOA) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_DBGU
value|((AT91PS_DBGU) 	0xFFFFF200)
end_define

begin_comment
comment|// (DBGU) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_DBGU
value|((AT91PS_PDC) 	0xFFFFF300)
end_define

begin_comment
comment|// (PDC_DBGU) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_AIC
value|((AT91PS_AIC) 	0xFFFFF000)
end_define

begin_comment
comment|// (AIC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_SPI
value|((AT91PS_PDC) 	0xFFFE0100)
end_define

begin_comment
comment|// (PDC_SPI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SPI
value|((AT91PS_SPI) 	0xFFFE0000)
end_define

begin_comment
comment|// (SPI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_SSC2
value|((AT91PS_PDC) 	0xFFFD8100)
end_define

begin_comment
comment|// (PDC_SSC2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SSC2
value|((AT91PS_SSC) 	0xFFFD8000)
end_define

begin_comment
comment|// (SSC2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_SSC1
value|((AT91PS_PDC) 	0xFFFD4100)
end_define

begin_comment
comment|// (PDC_SSC1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SSC1
value|((AT91PS_SSC) 	0xFFFD4000)
end_define

begin_comment
comment|// (SSC1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_SSC0
value|((AT91PS_PDC) 	0xFFFD0100)
end_define

begin_comment
comment|// (PDC_SSC0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SSC0
value|((AT91PS_SSC) 	0xFFFD0000)
end_define

begin_comment
comment|// (SSC0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_US3
value|((AT91PS_PDC) 	0xFFFCC100)
end_define

begin_comment
comment|// (PDC_US3) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_US3
value|((AT91PS_USART) 	0xFFFCC000)
end_define

begin_comment
comment|// (US3) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_US2
value|((AT91PS_PDC) 	0xFFFC8100)
end_define

begin_comment
comment|// (PDC_US2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_US2
value|((AT91PS_USART) 	0xFFFC8000)
end_define

begin_comment
comment|// (US2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_US1
value|((AT91PS_PDC) 	0xFFFC4100)
end_define

begin_comment
comment|// (PDC_US1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_US1
value|((AT91PS_USART) 	0xFFFC4000)
end_define

begin_comment
comment|// (US1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_US0
value|((AT91PS_PDC) 	0xFFFC0100)
end_define

begin_comment
comment|// (PDC_US0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_US0
value|((AT91PS_USART) 	0xFFFC0000)
end_define

begin_comment
comment|// (US0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TWI
value|((AT91PS_TWI) 	0xFFFB8000)
end_define

begin_comment
comment|// (TWI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_PDC_MCI
value|((AT91PS_PDC) 	0xFFFB4100)
end_define

begin_comment
comment|// (PDC_MCI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_MCI
value|((AT91PS_MCI) 	0xFFFB4000)
end_define

begin_comment
comment|// (MCI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_UDP
value|((AT91PS_UDP) 	0xFFFB0000)
end_define

begin_comment
comment|// (UDP) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC5
value|((AT91PS_TC) 	0xFFFA4080)
end_define

begin_comment
comment|// (TC5) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC4
value|((AT91PS_TC) 	0xFFFA4040)
end_define

begin_comment
comment|// (TC4) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC3
value|((AT91PS_TC) 	0xFFFA4000)
end_define

begin_comment
comment|// (TC3) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TCB1
value|((AT91PS_TCB) 	0xFFFA4080)
end_define

begin_comment
comment|// (TCB1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC2
value|((AT91PS_TC) 	0xFFFA0080)
end_define

begin_comment
comment|// (TC2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC1
value|((AT91PS_TC) 	0xFFFA0040)
end_define

begin_comment
comment|// (TC1) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TC0
value|((AT91PS_TC) 	0xFFFA0000)
end_define

begin_comment
comment|// (TC0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_TCB0
value|((AT91PS_TCB) 	0xFFFA0000)
end_define

begin_comment
comment|// (TCB0) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_UHP
value|((AT91PS_UHP) 	0x00300000)
end_define

begin_comment
comment|// (UHP) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_EMAC
value|((AT91PS_EMAC) 	0xFFFBC000)
end_define

begin_comment
comment|// (EMAC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_EBI
value|((AT91PS_EBI) 	0xFFFFFF60)
end_define

begin_comment
comment|// (EBI) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SMC2
value|((AT91PS_SMC2) 	0xFFFFFF70)
end_define

begin_comment
comment|// (SMC2) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_SDRC
value|((AT91PS_SDRC) 	0xFFFFFF90)
end_define

begin_comment
comment|// (SDRC) Base Address
end_comment

begin_define
define|#
directive|define
name|AT91C_BASE_BFC
value|((AT91PS_BFC) 	0xFFFFFFC0)
end_define

begin_comment
comment|// (BFC) Base Address
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               MEMORY MAPPING DEFINITIONS FOR AT91RM9200
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_ISRAM
value|((char *) 	0x00200000)
end_define

begin_comment
comment|// Internal SRAM base address
end_comment

begin_define
define|#
directive|define
name|AT91C_ISRAM_SIZE
value|((unsigned int) 0x00004000)
end_define

begin_comment
comment|// Internal SRAM size in byte (16 Kbyte)
end_comment

begin_define
define|#
directive|define
name|AT91C_IROM
value|((char *) 	0x00100000)
end_define

begin_comment
comment|// Internal ROM base address
end_comment

begin_define
define|#
directive|define
name|AT91C_IROM_SIZE
value|((unsigned int) 0x00020000)
end_define

begin_comment
comment|// Internal ROM size in byte (128 Kbyte)
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

