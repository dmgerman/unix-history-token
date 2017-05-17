begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007-2011 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MVWIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_MVWIN_H_
end_define

begin_comment
comment|/*  * Decode windows addresses.  *  * All decoding windows must be aligned to their size, which has to be  * a power of 2.  */
end_comment

begin_comment
comment|/*  * SoC Integrated devices: 0xF1000000, 16 MB (VA == PA)  */
end_comment

begin_comment
comment|/* SoC Regs */
end_comment

begin_define
define|#
directive|define
name|MV_PHYS_BASE
value|0xF1000000
end_define

begin_define
define|#
directive|define
name|MV_SIZE
value|(1024 * 1024)
end_define

begin_comment
comment|/* 1 MB */
end_comment

begin_comment
comment|/* SRAM */
end_comment

begin_define
define|#
directive|define
name|MV_CESA_SRAM_BASE
value|0xF1100000
end_define

begin_comment
comment|/*  * External devices: 0x80000000, 1 GB (VA == PA)  * Includes Device Bus, PCI and PCIE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_PCI_PORTS
value|2
end_define

begin_comment
comment|/* 1x PCI + 1x PCIE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_PCI_PORTS
value|1
end_define

begin_comment
comment|/* 1x PCIE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_PCI_PORTS
value|8
end_define

begin_comment
comment|/* 8x PCIE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_PCI_PORTS
value|3
end_define

begin_comment
comment|/* 3x PCIE */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_PCI_PORTS
value|4
end_define

begin_comment
comment|/* 4x PCIE */
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"MV_PCI_PORTS not configured !"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI/PCIE Memory */
end_comment

begin_define
define|#
directive|define
name|MV_PCI_MEM_PHYS_BASE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_SIZE
value|(512 * 1024 * 1024)
end_define

begin_comment
comment|/* 512 MB */
end_comment

begin_define
define|#
directive|define
name|MV_PCI_MEM_BASE
value|MV_PCI_MEM_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_SLICE_SIZE
value|(MV_PCI_MEM_SIZE / MV_PCI_PORTS)
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_SLICE
parameter_list|(
name|n
parameter_list|)
value|(MV_PCI_MEM_BASE + ((n) * \ 				    MV_PCI_MEM_SLICE_SIZE))
end_define

begin_comment
comment|/* PCI/PCIE I/O */
end_comment

begin_define
define|#
directive|define
name|MV_PCI_IO_PHYS_BASE
value|0xBF000000
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_SIZE
value|(16 * 1024 * 1024)
end_define

begin_comment
comment|/* 16 MB */
end_comment

begin_define
define|#
directive|define
name|MV_PCI_IO_BASE
value|MV_PCI_IO_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_SLICE_SIZE
value|(MV_PCI_IO_SIZE / MV_PCI_PORTS)
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_SLICE
parameter_list|(
name|n
parameter_list|)
value|(MV_PCI_IO_BASE + ((n) * MV_PCI_IO_SLICE_SIZE))
end_define

begin_define
define|#
directive|define
name|MV_PCI_VA_MEM_BASE
value|0
end_define

begin_define
define|#
directive|define
name|MV_PCI_VA_IO_BASE
value|0
end_define

begin_comment
comment|/*  * Device Bus (VA == PA)  */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_BOOT_BASE
value|0xF9300000
end_define

begin_define
define|#
directive|define
name|MV_DEV_BOOT_SIZE
value|(1024 * 1024)
end_define

begin_comment
comment|/* 1 MB */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS0_BASE
value|0xF9400000
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS0_SIZE
value|(1024 * 1024)
end_define

begin_comment
comment|/* 1 MB */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS1_BASE
value|0xF9500000
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS1_SIZE
value|(32 * 1024 * 1024)
end_define

begin_comment
comment|/* 32 MB */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS2_BASE
value|0xFB500000
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS2_SIZE
value|(1024 * 1024)
end_define

begin_comment
comment|/* 1 MB */
end_comment

begin_comment
comment|/*  * Integrated SoC peripherals addresses  */
end_comment

begin_define
define|#
directive|define
name|MV_BASE
value|MV_PHYS_BASE
end_define

begin_comment
comment|/* VA == PA mapping */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_DDR_CADR_BASE
value|(MV_BASE + 0x20180)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_DDR_CADR_BASE
value|(MV_BASE + 0x1500)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_MPP_BASE
value|(MV_BASE + 0x10000)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_MISC_BASE
value|(MV_BASE + 0x18200)
end_define

begin_define
define|#
directive|define
name|MV_MBUS_BRIDGE_BASE
value|(MV_BASE + 0x20000)
end_define

begin_define
define|#
directive|define
name|MV_INTREGS_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x80)
end_define

begin_define
define|#
directive|define
name|MV_MP_CLOCKS_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x700)
end_define

begin_define
define|#
directive|define
name|MV_CPU_CONTROL_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x1800)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_MBUS_BRIDGE_BASE
value|(MV_BASE + 0x20000)
end_define

begin_define
define|#
directive|define
name|MV_INTREGS_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x80)
end_define

begin_define
define|#
directive|define
name|MV_CPU_CONTROL_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_PCI_BASE
value|(MV_BASE + 0x30000)
end_define

begin_define
define|#
directive|define
name|MV_PCI_SIZE
value|0x2000
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_PCIE_BASE
value|(MV_BASE + 0x80000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_PCIE_BASE
value|(MV_BASE + 0x40000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_PCIE_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|MV_PCIE00_BASE
value|(MV_PCIE_BASE + 0x00000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE01_BASE
value|(MV_PCIE_BASE + 0x04000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE02_BASE
value|(MV_PCIE_BASE + 0x08000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE03_BASE
value|(MV_PCIE_BASE + 0x0C000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE10_BASE
value|(MV_PCIE_BASE + 0x40000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE11_BASE
value|(MV_PCIE_BASE + 0x44000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE12_BASE
value|(MV_PCIE_BASE + 0x48000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE13_BASE
value|(MV_PCIE_BASE + 0x4C000)
end_define

begin_define
define|#
directive|define
name|MV_SDIO_BASE
value|(MV_BASE + 0x90000)
end_define

begin_define
define|#
directive|define
name|MV_SDIO_SIZE
value|0x10000
end_define

begin_comment
comment|/*  * Decode windows definitions and macros  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_CPU_CTRL
parameter_list|(
name|n
parameter_list|)
value|(((n)< 8) ? 0x10 * (n) :  0x90 + (0x8 * ((n) - 8)))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_BASE
parameter_list|(
name|n
parameter_list|)
value|((((n)< 8) ? 0x10 * (n) :  0x90 + (0x8 * ((n) - 8))) + 0x4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_LO
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) +  0x008)
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_HI
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) +  0x00C)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_WIN_CPU_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x000 : 0x880))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x004 : 0x884))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_LO
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x008 : 0x888))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_HI
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x00C : 0x88C))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_CPU_MAX
value|14
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_CPU_MAX
value|20
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_WIN_CPU_MAX
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_WIN_CPU_ATTR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_TARGET_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_ENABLE_BIT
value|1
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x0)
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_MAX
value|4
end_define

begin_comment
comment|/*  * These values are valid only for peripherals decoding windows  * Bit in ATTR is zeroed according to CS bank number  */
end_comment

begin_define
define|#
directive|define
name|MV_WIN_DDR_ATTR
parameter_list|(
name|cs
parameter_list|)
value|(0x0F& ~(0x01<< (cs)))
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_TARGET
value|0x0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_CESA_TARGET
value|9
end_define

begin_define
define|#
directive|define
name|MV_WIN_CESA_ATTR
parameter_list|(
name|eng_sel
parameter_list|)
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_CESA_TARGET
value|9
end_define

begin_comment
comment|/*  * Bits [2:3] of cesa attribute select engine:  * eng_sel:  *  1: engine1  *  2: engine0  */
end_comment

begin_define
define|#
directive|define
name|MV_WIN_CESA_ATTR
parameter_list|(
name|eng_sel
parameter_list|)
value|(1 | ((eng_sel)<< 2))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_CESA_TARGET
value|9
end_define

begin_comment
comment|/*  * Bits [1:0] = Data swapping  *  0x0 = Byte swap  *  0x1 = No swap  *  0x2 = Byte and word swap  *  0x3 = Word swap  * Bits [4:2] = CESA select:  *  0x6 = CESA0  *  0x5 = CESA1  */
end_comment

begin_define
define|#
directive|define
name|MV_WIN_CESA_ATTR
parameter_list|(
name|eng_sel
parameter_list|)
value|(0x11 | (1<< (3 - (eng_sel))))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_WIN_CESA_TARGET
value|3
end_define

begin_define
define|#
directive|define
name|MV_WIN_CESA_ATTR
parameter_list|(
name|eng_sel
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_WIN_USB_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x320)
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x324)
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB3_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n))
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB3_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB3_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x200)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x204)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0x280)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_MAX
value|6
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0xa00)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0xa04)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0xa60)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_CAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0xa70)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MV_IDMA_CHAN_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_BASE
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x4 * (n) + 0xa50 + (m) * 0x100)
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_SIZE
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x4 * (n) + 0xa70 + (m) * 0x100)
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_REMAP
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x4 * (n) + 0xa90 + (m) * 0x100)
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_CTRL
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x4 * (n) + 0xa40 + (m) * 0x100)
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_OVERR
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x4 * (n) + 0xaa0 + (m) * 0x100)
end_define

begin_define
define|#
directive|define
name|MV_WIN_XOR_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MV_XOR_CHAN_MAX
value|2
end_define

begin_define
define|#
directive|define
name|MV_XOR_NON_REMAP
value|4
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_PCIE_TARGET
parameter_list|(
name|n
parameter_list|)
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MEM_ATTR
parameter_list|(
name|n
parameter_list|)
value|0xE8
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_IO_ATTR
parameter_list|(
name|n
parameter_list|)
value|0xE0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_PCIE_TARGET
parameter_list|(
name|n
parameter_list|)
value|(4 + (4 * ((n) % 2)))
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MEM_ATTR
parameter_list|(
name|n
parameter_list|)
value|(0xE8 + (0x10 * ((n) / 2)))
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_IO_ATTR
parameter_list|(
name|n
parameter_list|)
value|(0xE0 + (0x10 * ((n) / 2)))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_PCIE_TARGET
parameter_list|(
name|n
parameter_list|)
value|((n) == 0 ? 8 : 4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MEM_ATTR
parameter_list|(
name|n
parameter_list|)
value|((n)< 2 ? 0xE8 : (0xD8 - (((n) % 2) * 0x20)))
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_IO_ATTR
parameter_list|(
name|n
parameter_list|)
value|((n)< 2 ? 0xE0 : (0xD0 - (((n) % 2) * 0x20)))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_WIN_PCIE_TARGET
parameter_list|(
name|n
parameter_list|)
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MEM_ATTR
parameter_list|(
name|n
parameter_list|)
value|0x59
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_IO_ATTR
parameter_list|(
name|n
parameter_list|)
value|0x51
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_WIN_PCI_TARGET
value|3
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCI_MEM_ATTR
value|0x59
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCI_IO_ATTR
value|0x51
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x1820)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x1824)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x182C)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x04 * (n) + 0x1800)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x08 * ((n)< 3 ? (n) : 4) + 0x0010)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_BASE_H
parameter_list|(
name|n
parameter_list|)
value|(0x08 * (n) + 0x0014)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_64BIT
value|(0x4)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_PREFETCH_EN
value|(0x8)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_CONTROL
value|(0x1a00)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_ROOT_CMPLX
value|(1<< 1)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_SATA_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x60)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SATA_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x64)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SATA_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x68)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SATA_MAX
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_WIN_SATA_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x30)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SATA_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x34)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SATA_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_WIN_SDHCI_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x4080)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SDHCI_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x4084)
end_define

begin_define
define|#
directive|define
name|MV_WIN_SDHCI_MAX
value|8
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADA38X
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_BOOTROM_MEM_ADDR
value|0xFFF00000
end_define

begin_define
define|#
directive|define
name|MV_BOOTROM_WIN_SIZE
value|0xF
end_define

begin_define
define|#
directive|define
name|MV_CPU_SUBSYS_REGS_LEN
value|0x100
end_define

begin_define
define|#
directive|define
name|IO_WIN_9_CTRL_OFFSET
value|0x98
end_define

begin_define
define|#
directive|define
name|IO_WIN_9_BASE_OFFSET
value|0x9C
end_define

begin_comment
comment|/* Mbus decoding unit IDs and attributes */
end_comment

begin_define
define|#
directive|define
name|MBUS_BOOTROM_TGT_ID
value|0x1
end_define

begin_define
define|#
directive|define
name|MBUS_BOOTROM_ATTR
value|0x1D
end_define

begin_comment
comment|/* Internal Units Sync Barrier Control Register */
end_comment

begin_define
define|#
directive|define
name|MV_SYNC_BARRIER_CTRL
value|0x84
end_define

begin_define
define|#
directive|define
name|MV_SYNC_BARRIER_CTRL_ALL
value|0xFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IO Window Control Register fields */
end_comment

begin_define
define|#
directive|define
name|IO_WIN_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IO_WIN_SIZE_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IO_WIN_ATTR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IO_WIN_ATTR_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IO_WIN_TGT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IO_WIN_TGT_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|IO_WIN_SYNC_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|IO_WIN_SYNC_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|IO_WIN_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IO_WIN_ENA_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(int i)						\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off(i)));		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_RD2
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static  __inline uint32_t						\ 	pre ## _ ## reg ## _read(int i, int j)					\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off(i, j)));		\ 	}									\  #define WIN_REG_BASE_IDX_RD(pre,reg,off)					\ 	static __inline uint32_t						\ 	pre ## _ ## reg ## _read(uint32_t base, int i)				\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off(i)));		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_IDX_RD2
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(uint32_t base, int i, int j)				\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off(i, j)));		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(int i, uint32_t val)				\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off(i), val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_WR2
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(int i, int j, uint32_t val)			\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off(i, j), val);		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_IDX_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t base, int i, uint32_t val)		\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off(i), val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_IDX_WR2
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t base, int i, int j, uint32_t val)		\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off(i, j), val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(void)						\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off));			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(uint32_t base)					\ 	{									\ 		return (bus_space_read_4(fdtbus_bs_tag, base, off));			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t val)					\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off, val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t base, uint32_t val)			\ 	{									\ 		bus_space_write_4(fdtbus_bs_tag, base, off, val);			\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MVWIN_H_ */
end_comment

end_unit

