begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)device.h	7.4 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|driver
block|{
name|int
function_decl|(
modifier|*
name|d_init
function_decl|)
parameter_list|()
function_decl|;
name|char
modifier|*
name|d_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|d_start
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_go
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_intr
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_done
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hp_ctlr
block|{
name|struct
name|driver
modifier|*
name|hp_driver
decl_stmt|;
name|int
name|hp_unit
decl_stmt|;
name|int
name|hp_alive
decl_stmt|;
name|char
modifier|*
name|hp_addr
decl_stmt|;
name|int
name|hp_flags
decl_stmt|;
name|int
name|hp_ipl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hp_device
block|{
name|struct
name|driver
modifier|*
name|hp_driver
decl_stmt|;
name|struct
name|driver
modifier|*
name|hp_cdriver
decl_stmt|;
name|int
name|hp_unit
decl_stmt|;
name|int
name|hp_ctlr
decl_stmt|;
name|int
name|hp_slave
decl_stmt|;
name|char
modifier|*
name|hp_addr
decl_stmt|;
name|int
name|hp_dk
decl_stmt|;
name|int
name|hp_flags
decl_stmt|;
name|int
name|hp_alive
decl_stmt|;
name|int
name|hp_ipl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devqueue
block|{
name|struct
name|devqueue
modifier|*
name|dq_forw
decl_stmt|;
name|struct
name|devqueue
modifier|*
name|dq_back
decl_stmt|;
name|int
name|dq_ctlr
decl_stmt|;
name|int
name|dq_unit
decl_stmt|;
name|int
name|dq_slave
decl_stmt|;
name|struct
name|driver
modifier|*
name|dq_driver
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXCTLRS
value|16
end_define

begin_comment
comment|/* Size of HW table (arbitrary) */
end_comment

begin_define
define|#
directive|define
name|MAXSLAVES
value|8
end_define

begin_comment
comment|/* Slaves per controller (HPIB/SCSI limit) */
end_comment

begin_struct
struct|struct
name|hp_hw
block|{
name|caddr_t
name|hw_pa
decl_stmt|;
comment|/* physical address of control space */
name|int
name|hw_size
decl_stmt|;
comment|/* size of control space */
name|caddr_t
name|hw_kva
decl_stmt|;
comment|/* kernel virtual address of control space */
name|short
name|hw_id
decl_stmt|;
comment|/* HW returned id */
name|short
name|hw_secid
decl_stmt|;
comment|/* secondary HW id (displays) */
name|short
name|hw_type
decl_stmt|;
comment|/* type (defined below) */
name|short
name|hw_sc
decl_stmt|;
comment|/* select code (if applicable) */
block|}
struct|;
end_struct

begin_comment
comment|/* bus types */
end_comment

begin_define
define|#
directive|define
name|B_MASK
value|0xE000
end_define

begin_define
define|#
directive|define
name|B_DIO
value|0x2000
end_define

begin_define
define|#
directive|define
name|B_DIOII
value|0x4000
end_define

begin_define
define|#
directive|define
name|B_VME
value|0x6000
end_define

begin_comment
comment|/* controller types */
end_comment

begin_define
define|#
directive|define
name|C_MASK
value|0x8F
end_define

begin_define
define|#
directive|define
name|C_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|C_HPIB
value|0x81
end_define

begin_define
define|#
directive|define
name|C_SCSI
value|0x82
end_define

begin_define
define|#
directive|define
name|C_VME
value|0x83
end_define

begin_comment
comment|/* device types (controllers with no slaves) */
end_comment

begin_define
define|#
directive|define
name|D_MASK
value|0x8F
end_define

begin_define
define|#
directive|define
name|D_BITMAP
value|0x01
end_define

begin_define
define|#
directive|define
name|D_LAN
value|0x02
end_define

begin_define
define|#
directive|define
name|D_FPA
value|0x03
end_define

begin_define
define|#
directive|define
name|D_KEYBOARD
value|0x04
end_define

begin_define
define|#
directive|define
name|D_COMMDCA
value|0x05
end_define

begin_define
define|#
directive|define
name|D_COMMDCM
value|0x06
end_define

begin_define
define|#
directive|define
name|D_COMMDCL
value|0x07
end_define

begin_define
define|#
directive|define
name|D_PPORT
value|0x08
end_define

begin_define
define|#
directive|define
name|D_MISC
value|0x7F
end_define

begin_define
define|#
directive|define
name|HW_ISCTLR
parameter_list|(
name|hw
parameter_list|)
value|((hw)->hw_type& C_FLAG)
end_define

begin_define
define|#
directive|define
name|HW_ISDIOII
parameter_list|(
name|hw
parameter_list|)
value|((hw)->hw_type& B_DIOII)
end_define

begin_define
define|#
directive|define
name|HW_ISHPIB
parameter_list|(
name|hw
parameter_list|)
value|(((hw)->hw_type& C_MASK) == C_HPIB)
end_define

begin_define
define|#
directive|define
name|HW_ISSCSI
parameter_list|(
name|hw
parameter_list|)
value|(((hw)->hw_type& C_MASK) == C_SCSI)
end_define

begin_define
define|#
directive|define
name|HW_ISDEV
parameter_list|(
name|hw
parameter_list|,
name|d
parameter_list|)
value|(((hw)->hw_type& D_MASK) == (d))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|hp_hw
name|sc_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hp_ctlr
name|hp_cinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hp_device
name|hp_dinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|sctova
argument_list|()
decl_stmt|,
name|sctopa
argument_list|()
decl_stmt|,
name|iomap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

