begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)if_enpreg.h	7.1 (Berkeley) 5/31/88  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984 by Communication Machinery Corporation  *  *	This file contains material which is proprietary to  *	Communication Machinery Corporation (CMC) and which  *	may not be divulged without the written permission  *	of CMC.  *  *	ENP-10 Ram Definition  *  *	3/15/85 Jon Phares  *	Update 7/10/85 S. Holmgren  *	ENP-10 update 7/21/85 J. Mullen  *	ENP-20 update 8/11/85 J. Mullen  *	Mods for CCI TAHOE system 8/14/85 J. Mullen  */
end_comment

begin_define
define|#
directive|define
name|K
value|*1024
end_define

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|ea_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|ethlist
block|{
name|int
name|e_listsize
decl_stmt|;
comment|/* active addr entries */
name|struct
name|ether_addr
name|e_baseaddr
decl_stmt|;
comment|/* addr lance is working with */
name|struct
name|ether_addr
name|e_addrs
index|[
literal|16
index|]
decl_stmt|;
comment|/* possible addresses */
block|}
name|ETHLIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|e_xmit_successful
decl_stmt|;
comment|/* Successful transmissions */
name|u_long
name|e_mult_retry
decl_stmt|;
comment|/* multiple retries on xmit */
name|u_long
name|e_one_retry
decl_stmt|;
comment|/* single retries */
name|u_long
name|e_fail_retry
decl_stmt|;
comment|/* too many retries */
name|u_long
name|e_deferrals
decl_stmt|;
comment|/* xmit delayed 'cuz cable busy */
name|u_long
name|e_xmit_buff_err
decl_stmt|;
comment|/* xmit data chaining failed -- 						   "can't happen" */
name|u_long
name|e_silo_underrun
decl_stmt|;
comment|/* transmit data fetch failed */
name|u_long
name|e_late_coll
decl_stmt|;
comment|/* collision after xmit */
name|u_long
name|e_lost_carrier
decl_stmt|;
name|u_long
name|e_babble
decl_stmt|;
comment|/* xmit length> 1518 */
name|u_long
name|e_collision
decl_stmt|;
name|u_long
name|e_xmit_mem_err
decl_stmt|;
name|u_long
name|e_rcv_successful
decl_stmt|;
comment|/* good receptions */
name|u_long
name|e_rcv_missed
decl_stmt|;
comment|/* no recv buff available */
name|u_long
name|e_crc_err
decl_stmt|;
comment|/* checksum failed */
name|u_long
name|e_frame_err
decl_stmt|;
comment|/* crc error& data length != 0 mod 8 */
name|u_long
name|e_rcv_buff_err
decl_stmt|;
comment|/* rcv data chain failure -- 						   "can't happen" */
name|u_long
name|e_silo_overrun
decl_stmt|;
comment|/* receive data store failed */
name|u_long
name|e_rcv_mem_err
decl_stmt|;
block|}
name|ENPSTAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RING
block|{
name|short
name|r_rdidx
decl_stmt|;
name|short
name|r_wrtidx
decl_stmt|;
name|short
name|r_size
decl_stmt|;
name|short
name|r_pad
decl_stmt|;
name|int
name|r_slot
index|[
literal|1
index|]
decl_stmt|;
block|}
name|RING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RING32
block|{
name|short
name|r_rdidx
decl_stmt|;
name|short
name|r_wrtidx
decl_stmt|;
name|short
name|r_size
decl_stmt|;
name|short
name|r_pad
decl_stmt|;
comment|/* to make VAXen happy */
name|int
name|r_slot
index|[
literal|32
index|]
decl_stmt|;
block|}
name|RING32
typedef|;
end_typedef

begin_comment
comment|/*  * ENP Ram data layout  */
end_comment

begin_comment
comment|/*  * Note: paged window (4 K) is identity mapped by ENP kernel to provide  * 124 K contiguous RAM (as reflected in RAM_SIZE)  */
end_comment

begin_define
define|#
directive|define
name|RAM_WINDOW
value|(128 K)
end_define

begin_define
define|#
directive|define
name|IOACCESS_WINDOW
value|(512)
end_define

begin_define
define|#
directive|define
name|FIXED_WINDOW
value|(RAM_WINDOW - IOACCESS_WINDOW)
end_define

begin_define
define|#
directive|define
name|RAMROM_SWAP
value|(4 K)
end_define

begin_define
define|#
directive|define
name|RAM_SIZE
value|(FIXED_WINDOW - RAMROM_SWAP)
end_define

begin_define
define|#
directive|define
name|HOST_RAMSIZE
value|(48 K)
end_define

begin_define
define|#
directive|define
name|ENP_RAMSIZE
value|(20 K)
end_define

begin_typedef
typedef|typedef
struct|struct
name|iow20
block|{
name|char
name|pad0
decl_stmt|;
name|char
name|hst2enp_interrupt
decl_stmt|;
name|char
name|pad1
index|[
literal|510
index|]
decl_stmt|;
block|}
name|iow20
typedef|;
end_typedef

begin_struct
struct|struct
name|enpdevice
block|{
ifdef|#
directive|ifdef
name|notdef
name|char
name|enp_ram_rom
index|[
literal|4
name|K
index|]
decl_stmt|;
endif|#
directive|endif
endif|notdef
union|union
block|{
name|char
name|all_ram
index|[
name|RAM_SIZE
index|]
decl_stmt|;
struct|struct
block|{
name|u_int
name|t_go
decl_stmt|;
name|u_int
name|t_pstart
decl_stmt|;
block|}
name|t
struct|;
struct|struct
block|{
name|char
name|nram
index|[
name|RAM_SIZE
operator|-
operator|(
name|HOST_RAMSIZE
operator|+
name|ENP_RAMSIZE
operator|)
index|]
decl_stmt|;
name|char
name|hram
index|[
name|HOST_RAMSIZE
index|]
decl_stmt|;
name|char
name|kram
index|[
name|ENP_RAMSIZE
index|]
decl_stmt|;
block|}
name|u_ram
struct|;
struct|struct
block|{
name|char
name|pad7
index|[
literal|0x100
index|]
decl_stmt|;
comment|/* starts 0x1100 - 0x2000 */
name|short
name|e_enpstate
decl_stmt|;
comment|/* 1102 */
name|short
name|e_enpmode
decl_stmt|;
comment|/* 1104 */
name|int
name|e_enpbase
decl_stmt|;
comment|/* 1104 */
name|int
name|e_enprun
decl_stmt|;
comment|/* 1108 */
name|u_short
name|e_intrvec
decl_stmt|;
name|u_short
name|e_dummy
index|[
literal|3
index|]
decl_stmt|;
name|RING32
name|h_toenp
decl_stmt|;
comment|/* 110C */
name|RING32
name|h_hostfree
decl_stmt|;
name|RING32
name|e_tohost
decl_stmt|;
name|RING32
name|e_enpfree
decl_stmt|;
name|ENPSTAT
name|e_stat
decl_stmt|;
name|ETHLIST
name|e_netaddr
decl_stmt|;
block|}
name|iface
struct|;
block|}
name|enp_u
union|;
name|iow20
name|enp_iow
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|enp_ram
value|enp_u.all_ram
end_define

begin_define
define|#
directive|define
name|enp_nram
value|enp_u.u_ram.nram
end_define

begin_define
define|#
directive|define
name|enp_hram
value|enp_u.u_ram.hram
end_define

begin_define
define|#
directive|define
name|enp_kram
value|enp_u.u_ram.kram
end_define

begin_define
define|#
directive|define
name|enp_go
value|enp_u.t.t_go
end_define

begin_define
define|#
directive|define
name|enp_prog_start
value|enp_u.t.t_pstart
end_define

begin_define
define|#
directive|define
name|enp_intrvec
value|enp_u.iface.e_intrvec
end_define

begin_define
define|#
directive|define
name|enp_state
value|enp_u.iface.e_enpstate
end_define

begin_define
define|#
directive|define
name|enp_mode
value|enp_u.iface.e_enpmode
end_define

begin_define
define|#
directive|define
name|enp_base
value|enp_u.iface.e_enpbase
end_define

begin_define
define|#
directive|define
name|enp_enprun
value|enp_u.iface.e_enprun
end_define

begin_define
define|#
directive|define
name|enp_toenp
value|enp_u.iface.h_toenp
end_define

begin_define
define|#
directive|define
name|enp_hostfree
value|enp_u.iface.h_hostfree
end_define

begin_define
define|#
directive|define
name|enp_tohost
value|enp_u.iface.e_tohost
end_define

begin_define
define|#
directive|define
name|enp_enpfree
value|enp_u.iface.e_enpfree
end_define

begin_define
define|#
directive|define
name|enp_freembuf
value|enp_u.iface.h_freembuf
end_define

begin_define
define|#
directive|define
name|enp_stat
value|enp_u.iface.e_stat
end_define

begin_define
define|#
directive|define
name|enp_addr
value|enp_u.iface.e_netaddr
end_define

begin_define
define|#
directive|define
name|ENPVAL
value|0xff
end_define

begin_comment
comment|/* enp_iow.hst2enp_interrupt poke value */
end_comment

begin_define
define|#
directive|define
name|RESETVAL
value|0x00
end_define

begin_comment
comment|/* enp_iow.enp2hst_clear_intr poke value */
end_comment

begin_define
define|#
directive|define
name|INTR_ENP
parameter_list|(
name|addr
parameter_list|)
value|(addr->enp_iow.hst2enp_interrupt = ENPVAL)
end_define

begin_if
if|#
directive|if
name|ENP
operator|==
literal|30
end_if

begin_define
define|#
directive|define
name|ACK_ENP_INTR
parameter_list|(
name|addr
parameter_list|)
value|(addr->enp_iow.enp2hst_clear_intr = RESETVAL)
end_define

begin_define
define|#
directive|define
name|IS_ENP_INTR
parameter_list|(
name|addr
parameter_list|)
value|(addr->enp_iow.enp2hst_clear_intr&0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|RESET_ENP
parameter_list|(
name|addr
parameter_list|)
value|(addr->enp_iow.hst2enp_reset = 01)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|RESET_ENP
parameter_list|(
name|addr
parameter_list|)
value|((addr) = (addr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RESET_ENP
parameter_list|(
name|addr
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
endif|notdef
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|ENP_GO
parameter_list|(
name|addr
parameter_list|,
name|start
parameter_list|)
value|{ \ 	int v = start; \ 	enpcopy((u_char *)&v, (u_char *)&addr->enp_prog_start, sizeof(v) ); \ 	v = 0x80800000; \ 	enpcopy((u_char *)&v, (u_char *)&addr->enp_go, sizeof(v) ); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENP_GO
parameter_list|(
name|addr
parameter_list|,
name|start
parameter_list|,
name|intvec
parameter_list|)
value|{ \ 	addr->enp_prog_start = (u_int)(start); \ 	addr->enp_intrvec = (u_short) intvec; \ 	addr->enp_go = 0x80800000; \ }
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_comment
comment|/*  * State bits  */
end_comment

begin_define
define|#
directive|define
name|S_ENPRESET
value|01
end_define

begin_comment
comment|/* enp is in reset state */
end_comment

begin_define
define|#
directive|define
name|S_ENPRUN
value|02
end_define

begin_comment
comment|/* enp is in run state */
end_comment

begin_comment
comment|/*  * Mode bits  */
end_comment

begin_define
define|#
directive|define
name|E_SWAP16
value|0x1
end_define

begin_comment
comment|/* swap two octets within 16 */
end_comment

begin_define
define|#
directive|define
name|E_SWAP32
value|0x2
end_define

begin_comment
comment|/* swap 16s within 32 */
end_comment

begin_define
define|#
directive|define
name|E_SWAPRD
value|0x4
end_define

begin_comment
comment|/* swap on read */
end_comment

begin_define
define|#
directive|define
name|E_SWAPWRT
value|0x8
end_define

begin_comment
comment|/* swap on write */
end_comment

begin_define
define|#
directive|define
name|E_DMA
value|0x10
end_define

begin_comment
comment|/* enp does data moving */
end_comment

begin_define
define|#
directive|define
name|E_EXAM_LIST
value|0x80000000
end_define

begin_comment
comment|/* enp should examine addrlist */
end_comment

begin_define
define|#
directive|define
name|E_ADDR_SUPP
value|0x40000000
end_define

begin_comment
comment|/* enp should use supplied addr */
end_comment

begin_comment
comment|/*  * Download ioctl definitions  */
end_comment

begin_define
define|#
directive|define
name|ENPIOGO
value|_IO('S',1)
end_define

begin_comment
comment|/* start the enp */
end_comment

begin_define
define|#
directive|define
name|ENPIORESET
value|_IO('S',2)
end_define

begin_comment
comment|/* reset the enp */
end_comment

begin_comment
comment|/*  * The ENP Data Buffer Structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BCB
block|{
name|struct
name|BCB
modifier|*
name|b_link
decl_stmt|;
name|short
name|b_stat
decl_stmt|;
name|short
name|b_len
decl_stmt|;
name|u_char
modifier|*
name|b_addr
decl_stmt|;
name|short
name|b_msglen
decl_stmt|;
name|short
name|b_reserved
decl_stmt|;
block|}
name|BCB
typedef|;
end_typedef

end_unit

