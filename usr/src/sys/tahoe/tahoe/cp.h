begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cp.h	1.1	86/01/05	*/
end_comment

begin_comment
comment|/*	Console Processor Interface 	*/
end_comment

begin_comment
comment|/*	Tahoe version, Nov. 1982	*/
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*					*/
end_comment

begin_comment
comment|/*	Reduced DCB layout for byte	*/
end_comment

begin_comment
comment|/*	communication.			*/
end_comment

begin_comment
comment|/*					*/
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_define
define|#
directive|define
name|CPBUFLEN
value|200
end_define

begin_comment
comment|/* Output buffer length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|cphdr
block|{
name|char
name|cp_unit
decl_stmt|;
comment|/* Done bit& unit # */
name|char
name|cp_comm
decl_stmt|;
comment|/* Command */
name|short
name|cp_count
decl_stmt|;
comment|/* Counter (when relevant) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpdcb_o
comment|/* Output structure */
block|{
name|struct
name|cphdr
name|cp_hdr
decl_stmt|;
name|char
name|cp_buf
index|[
name|CPBUFLEN
index|]
decl_stmt|;
comment|/* Buffer for output or 'stty' */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpdcb_i
comment|/* Structure for input */
block|{
name|struct
name|cphdr
name|cp_hdr
decl_stmt|;
name|char
name|cpi_buf
index|[
literal|4
index|]
decl_stmt|;
comment|/* Buffer for input */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPDONE
value|0x80
end_define

begin_comment
comment|/* 'Done' bit in cp_unit */
end_comment

begin_define
define|#
directive|define
name|CPTAKE
value|0x40
end_define

begin_comment
comment|/* CP 'ack' to this cpdcb */
end_comment

begin_comment
comment|/* Values for 'unit' */
end_comment

begin_define
define|#
directive|define
name|CPUNIT
value|0
end_define

begin_comment
comment|/* The CP itself */
end_comment

begin_define
define|#
directive|define
name|CPCONS
value|1
end_define

begin_comment
comment|/* Console line */
end_comment

begin_define
define|#
directive|define
name|CPREMOT
value|2
end_define

begin_comment
comment|/* Remote line */
end_comment

begin_comment
comment|/* Values for 'command' */
end_comment

begin_define
define|#
directive|define
name|CPRESET
value|0
end_define

begin_define
define|#
directive|define
name|CPWRITE
value|1
end_define

begin_define
define|#
directive|define
name|CPREAD
value|2
end_define

begin_define
define|#
directive|define
name|CPSTTY
value|3
end_define

begin_define
define|#
directive|define
name|CPBOOT
value|4
end_define

end_unit

