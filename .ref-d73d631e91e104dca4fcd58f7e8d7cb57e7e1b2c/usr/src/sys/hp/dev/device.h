begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)device.h	7.2 (Berkeley) %G%  */
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

begin_struct
struct|struct
name|hp_hw
block|{
name|char
modifier|*
name|hw_addr
decl_stmt|;
comment|/* physical address of registers */
name|short
name|hw_sc
decl_stmt|;
comment|/* select code (if applicable) */
name|short
name|hw_type
decl_stmt|;
comment|/* type (defined below) */
name|short
name|hw_id
decl_stmt|;
comment|/* HW returned id */
name|short
name|hw_id2
decl_stmt|;
comment|/* secondary HW id (displays) */
name|char
modifier|*
name|hw_name
decl_stmt|;
comment|/* HP product name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_CTLR
value|16
end_define

begin_comment
comment|/* Totally arbitrary */
end_comment

begin_define
define|#
directive|define
name|MAXSLAVES
value|8
end_define

begin_comment
comment|/* Currently the HPIB limit */
end_comment

begin_define
define|#
directive|define
name|WILD_CARD_CTLR
value|0
end_define

begin_comment
comment|/* A controller is a card which can have one or more slaves attached */
end_comment

begin_define
define|#
directive|define
name|CONTROLLER
value|0x10
end_define

begin_define
define|#
directive|define
name|HPIB
value|0x16
end_define

begin_define
define|#
directive|define
name|SCSI
value|0x17
end_define

begin_define
define|#
directive|define
name|VME
value|0x18
end_define

begin_define
define|#
directive|define
name|FLINK
value|0x19
end_define

begin_comment
comment|/* Slaves are devices which attach to controllers, e.g. disks, tapes */
end_comment

begin_define
define|#
directive|define
name|RD
value|0x2a
end_define

begin_define
define|#
directive|define
name|PPI
value|0x2b
end_define

begin_define
define|#
directive|define
name|CT
value|0x2c
end_define

begin_comment
comment|/* These are not controllers, but may have their own HPIB address */
end_comment

begin_define
define|#
directive|define
name|BITMAP
value|1
end_define

begin_define
define|#
directive|define
name|NET
value|2
end_define

begin_define
define|#
directive|define
name|FPA
value|4
end_define

begin_define
define|#
directive|define
name|MISC
value|5
end_define

begin_define
define|#
directive|define
name|KEYBOARD
value|6
end_define

begin_define
define|#
directive|define
name|COMMDCA
value|7
end_define

begin_define
define|#
directive|define
name|COMMDCM
value|8
end_define

begin_define
define|#
directive|define
name|COMMDCL
value|9
end_define

begin_define
define|#
directive|define
name|PPORT
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
name|struct
name|hp_hw
name|sc_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

