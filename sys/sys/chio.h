begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 16 Feb 93	Julian Elischer		ADDED for SCSI system  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* This is a "convertet" mtio.h from 386BSD    Stefan Grefen grefen@goofy.zdv.uni-mainz.de  */
end_comment

begin_comment
comment|/*  * Structures and definitions for changer io control commands  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CHIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CHIO_H_
end_define

begin_define
define|#
directive|define
name|CH_INVERT
value|0x10000
end_define

begin_define
define|#
directive|define
name|CH_ADDR_MASK
value|0xffff
end_define

begin_struct
struct|struct
name|chop
block|{
name|short
name|ch_op
decl_stmt|;
comment|/* operations defined below */
name|short
name|result
decl_stmt|;
comment|/* The result		    */
union|union
block|{
struct|struct
block|{
name|int
name|chm
decl_stmt|;
comment|/* Transport element */
name|int
name|from
decl_stmt|;
name|int
name|to
decl_stmt|;
block|}
name|move
struct|;
struct|struct
block|{
name|int
name|chm
decl_stmt|;
comment|/* Transport element */
name|int
name|to
decl_stmt|;
block|}
name|position
struct|;
struct|struct
block|{
name|short
name|chmo
decl_stmt|;
comment|/* Offset of first CHM */
name|short
name|chms
decl_stmt|;
comment|/* No. of CHM */
name|short
name|slots
decl_stmt|;
comment|/* No. of Storage Elements */
name|short
name|sloto
decl_stmt|;
comment|/* Offset of first SE */
name|short
name|imexs
decl_stmt|;
comment|/* No. of Import/Export Slots */
name|short
name|imexo
decl_stmt|;
comment|/* Offset of first IM/EX */
name|short
name|drives
decl_stmt|;
comment|/* No. of CTS */
name|short
name|driveo
decl_stmt|;
comment|/* Offset of first CTS */
name|short
name|rot
decl_stmt|;
comment|/* CHM can rotate */
block|}
name|getparam
struct|;
struct|struct
block|{
name|int
name|type
decl_stmt|;
define|#
directive|define
name|CH_CHM
value|1
define|#
directive|define
name|CH_STOR
value|2
define|#
directive|define
name|CH_IMEX
value|3
define|#
directive|define
name|CH_CTS
value|4
name|int
name|from
decl_stmt|;
struct|struct
block|{
name|u_char
name|elema_1
decl_stmt|;
name|u_char
name|elema_0
decl_stmt|;
name|u_char
name|full
range|:
literal|1
decl_stmt|;
name|u_char
name|rsvd
range|:
literal|1
decl_stmt|;
name|u_char
name|except
range|:
literal|1
decl_stmt|;
name|u_char
label|:
literal|5
expr_stmt|;
name|u_char
name|rsvd2
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_char
name|add_sense_code
decl_stmt|;
name|u_char
name|add_sense_code_qualifier
decl_stmt|;
block|}
name|specs
struct|;
name|short
name|add_sense
decl_stmt|;
comment|/* WARINING LSB only */
define|#
directive|define
name|CH_CHOLDER
value|0x0290
comment|/* Cartridge holder is missing */
define|#
directive|define
name|CH_STATUSQ
value|0x0390
comment|/* Status is questionable */
define|#
directive|define
name|CH_CTS_CLOSED
value|0x0490
comment|/* CTS door is closed */
block|}
name|ch_add_sense
union|;
name|u_char
name|rsvd3
index|[
literal|3
index|]
decl_stmt|;
name|u_char
label|:
literal|6
expr_stmt|;
name|u_char
name|invert
range|:
literal|1
decl_stmt|;
name|u_char
name|svalid
range|:
literal|1
decl_stmt|;
name|u_char
name|source_1
decl_stmt|;
name|u_char
name|source_0
decl_stmt|;
name|u_char
name|rsvd4
index|[
literal|4
index|]
decl_stmt|;
block|}
name|elem_data
struct|;
block|}
name|get_elem_stat
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* operations */
end_comment

begin_define
define|#
directive|define
name|CHMOVE
value|1
end_define

begin_define
define|#
directive|define
name|CHPOSITION
value|2
end_define

begin_define
define|#
directive|define
name|CHGETPARAM
value|3
end_define

begin_define
define|#
directive|define
name|CHGETELEM
value|4
end_define

begin_comment
comment|/* Changer IO control command */
end_comment

begin_define
define|#
directive|define
name|CHIOOP
value|_IOWR('c', 1, struct chop)
end_define

begin_comment
comment|/* do a mag tape op */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SYS_CHIO_H*/
end_comment

end_unit

