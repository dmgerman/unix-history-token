begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_BOARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_BOARD_H_
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_I
value|1
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_II
value|2
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_III
value|3
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_IV
value|4
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_V
value|5
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VI
value|6
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VII
value|7
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VIII
value|8
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_A0
value|0x0c0600
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_A0
value|0x0c0700
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_A0
value|0x0c0800
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_A0
value|0x0c0900
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_A0
value|0x0c0a00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_A0
value|0x0c0b00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_A1
value|0x0c0601
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_A1
value|0x0c0701
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_A1
value|0x0c0801
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_A1
value|0x0c0901
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_A1
value|0x0c0a01
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_A1
value|0x0c0b01
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_B0
value|0x0c0602
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_B0
value|0x0c0702
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_B0
value|0x0c0802
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_B0
value|0x0c0902
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_B0
value|0x0c0a02
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_B0
value|0x0c0b02
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_B1
value|0x0c0603
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_B1
value|0x0c0703
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_B1
value|0x0c0803
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_B1
value|0x0c0903
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_B1
value|0x0c0a03
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_B1
value|0x0c0b03
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_B2
value|0x0c0604
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_B2
value|0x0c0704
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_B2
value|0x0c0804
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_B2
value|0x0c0904
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_B2
value|0x0c0a04
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_B2
value|0x0c0b04
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C0
value|0x0c0705
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C0
value|0x0c0b05
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C0
value|0x0c0a05
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C0
value|0x0c0805
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_C0
value|0x0c0205
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_C0
value|0x0c0005
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C1
value|0x0c0706
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C1
value|0x0c0b06
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C1
value|0x0c0a06
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C1
value|0x0c0806
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_C1
value|0x0c0206
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_C1
value|0x0c0006
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C2
value|0x0c0707
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C2
value|0x0c0b07
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C2
value|0x0c0a07
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C2
value|0x0c0807
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_C2
value|0x0c0207
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_C2
value|0x0c0007
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C3
value|0x0c0708
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C3
value|0x0c0b08
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C3
value|0x0c0a08
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C3
value|0x0c0808
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_C3
value|0x0c0208
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_C3
value|0x0c0008
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C4
value|0x0c0709
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C4
value|0x0c0b09
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C4
value|0x0c0a09
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C4
value|0x0c0809
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716_C4
value|0x0c0209
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732_C4
value|0x0c0009
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS608_A0
value|0x0c8000
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS408_A0
value|0x0c8800
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS404_A0
value|0x0c8c00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS208_A0
value|0x0c8e00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS204_A0
value|0x0c8f00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS608_A1
value|0x0c8001
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS408_A1
value|0x0c8801
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS404_A1
value|0x0c8c01
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS208_A1
value|0x0c8e01
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS204_A1
value|0x0c8f01
end_define

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|xlr_revision
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|mips_rd_prid
argument_list|()
operator|&
literal|0xff00ff
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|xlr_is_xls
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|prid
init|=
name|mips_rd_prid
argument_list|()
decl_stmt|;
return|return
operator|(
name|prid
operator|&
literal|0xf000
operator|)
operator|==
literal|0x8000
operator|||
operator|(
name|prid
operator|&
literal|0xf000
operator|)
operator|==
literal|0x4000
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_revision_a0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_revision
argument_list|()
operator|==
literal|0x0c0000
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_revision_b0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_revision
argument_list|()
operator|==
literal|0x0c0002
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_revision_b1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_revision
argument_list|()
operator|==
literal|0x0c0003
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_i
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_I
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_ii
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_II
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_ii_b
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_II
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_iii
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_III
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_iv
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_IV
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_iv_b
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_IV
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_v
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_V
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_vi
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_VI
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_iii_256
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_III
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_iii_512
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_III
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_atx_v_512
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_boot1_info
operator|.
name|board_major_version
operator|==
name|RMI_XLR_BOARD_ARIZONA_V
operator|)
operator|&&
operator|(
name|xlr_boot1_info
operator|.
name|board_minor_version
operator|==
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_board_pci
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_board_atx_iii_256
argument_list|()
operator|||
name|xlr_board_atx_iii_512
argument_list|()
operator|||
name|xlr_board_atx_v_512
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_is_xls2xx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|mips_rd_prid
argument_list|()
operator|&
literal|0xffffff00U
decl_stmt|;
return|return
name|chipid
operator|==
literal|0x0c8e00
operator|||
name|chipid
operator|==
literal|0x0c8f00
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|xlr_is_xls4xx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|mips_rd_prid
argument_list|()
operator|&
literal|0xffffff00U
decl_stmt|;
return|return
name|chipid
operator|==
literal|0x0c8800
operator|||
name|chipid
operator|==
literal|0x0c8c00
return|;
block|}
end_function

begin_comment
comment|/* all our knowledge of chip and board that cannot be detected run-time goes here */
end_comment

begin_enum
enum|enum
name|gmac_block_types
block|{
name|XLR_GMAC
block|,
name|XLR_XGMAC
block|,
name|XLR_SPI4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|gmac_block_modes
block|{
name|XLR_RGMII
block|,
name|XLR_SGMII
block|,
name|XLR_PORT0_RGMII
block|}
enum|;
end_enum

begin_struct
struct|struct
name|xlr_board_info
block|{
name|int
name|is_xls
decl_stmt|;
name|int
name|nr_cpus
decl_stmt|;
name|int
name|usb
decl_stmt|;
comment|/* usb enabled ? */
name|int
name|cfi
decl_stmt|;
comment|/* compact flash driver for NOR? */
name|int
name|pci_irq
decl_stmt|;
name|struct
name|stn_cc
modifier|*
modifier|*
name|credit_configs
decl_stmt|;
comment|/* pointer to Core station credits */
name|struct
name|bucket_size
modifier|*
name|bucket_sizes
decl_stmt|;
comment|/* pointer to Core station 						 * bucket */
name|int
modifier|*
name|msgmap
decl_stmt|;
comment|/* mapping of message station to devices */
name|int
name|gmacports
decl_stmt|;
comment|/* number of gmac ports on the board */
struct|struct
name|xlr_gmac_block_t
block|{
name|int
name|type
decl_stmt|;
comment|/* see  enum gmac_block_types */
name|unsigned
name|int
name|enabled
decl_stmt|;
comment|/* mask of ports enabled */
name|struct
name|stn_cc
modifier|*
name|credit_config
decl_stmt|;
comment|/* credit configuration */
name|int
name|station_txbase
decl_stmt|;
comment|/* station id for tx */
name|int
name|station_rfr
decl_stmt|;
comment|/* free desc bucket */
name|int
name|mode
decl_stmt|;
comment|/* see gmac_block_modes */
name|uint32_t
name|baseaddr
decl_stmt|;
comment|/* IO base */
name|int
name|baseirq
decl_stmt|;
comment|/* first irq for this block, the rest are in 				 * sequence */
name|int
name|baseinst
decl_stmt|;
comment|/* the first rge unit for this block */
block|}
name|gmac_block
index|[
literal|3
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|xlr_board_info
name|xlr_board_info
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|xlr_board_info_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

