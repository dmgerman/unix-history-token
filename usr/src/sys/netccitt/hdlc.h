begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * %sccs.include.redist.c%  *  *	@(#)hdlc.h	7.2 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_typedef
typedef|typedef
name|u_char
name|octet
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_INFO_LEN
value|4096+3+4
end_define

begin_define
define|#
directive|define
name|ADDRESS_A
value|3
end_define

begin_comment
comment|/* B'00000011' */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_B
value|1
end_define

begin_comment
comment|/* B'00000001' */
end_comment

begin_struct
struct|struct
name|Hdlc_iframe
block|{
name|octet
name|address
decl_stmt|;
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|hdlc_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|ns
range|:
literal|3
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|nr
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|nr
range|:
literal|3
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|ns
range|:
literal|3
decl_stmt|;
name|unsigned
name|hdlc_0
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|char
name|i_field
index|[
name|MAX_INFO_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hdlc_sframe
block|{
name|octet
name|address
decl_stmt|;
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|hdlc_01
range|:
literal|2
decl_stmt|;
name|unsigned
name|s2
range|:
literal|2
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|nr
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|nr
range|:
literal|3
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|s2
range|:
literal|2
decl_stmt|;
name|unsigned
name|hdlc_01
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hdlc_uframe
block|{
name|octet
name|address
decl_stmt|;
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|hdlc_11
range|:
literal|2
decl_stmt|;
name|unsigned
name|m2
range|:
literal|2
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|m3
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|m3
range|:
literal|3
decl_stmt|;
name|unsigned
name|pf
range|:
literal|1
decl_stmt|;
name|unsigned
name|m2
range|:
literal|2
decl_stmt|;
name|unsigned
name|hdlc_11
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Frmr_frame
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|control
decl_stmt|;
name|octet
name|frmr_control
decl_stmt|;
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|frmr_f2_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_ns
range|:
literal|3
decl_stmt|;
name|unsigned
name|frmr_f1_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_nr
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|frmr_nr
range|:
literal|3
decl_stmt|;
name|unsigned
name|frmr_f1_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_ns
range|:
literal|3
decl_stmt|;
name|unsigned
name|frmr_f2_0
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|frmr_w
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_x
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_y
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_z
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_0000
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|frmr_0000
range|:
literal|4
decl_stmt|;
name|unsigned
name|frmr_z
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_y
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_x
range|:
literal|1
decl_stmt|;
name|unsigned
name|frmr_w
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDHEADERLN
value|2
end_define

begin_define
define|#
directive|define
name|MINFRLN
value|2
end_define

begin_comment
comment|/* Minimum frame length. */
end_comment

begin_struct
struct|struct
name|Hdlc_frame
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|control
decl_stmt|;
name|char
name|info
index|[
literal|3
index|]
decl_stmt|;
comment|/* min for FRMR */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SABM_CONTROL
value|057
end_define

begin_comment
comment|/* B'00101111' */
end_comment

begin_define
define|#
directive|define
name|UA_CONTROL
value|0143
end_define

begin_comment
comment|/* B'01100011' */
end_comment

begin_define
define|#
directive|define
name|DISC_CONTROL
value|0103
end_define

begin_comment
comment|/* B'01000011' */
end_comment

begin_define
define|#
directive|define
name|DM_CONTROL
value|017
end_define

begin_comment
comment|/* B'00001111' */
end_comment

begin_define
define|#
directive|define
name|FRMR_CONTROL
value|0207
end_define

begin_comment
comment|/* B'10000111' */
end_comment

begin_define
define|#
directive|define
name|RR_CONTROL
value|01
end_define

begin_comment
comment|/* B'00000001' */
end_comment

begin_define
define|#
directive|define
name|RNR_CONTROL
value|05
end_define

begin_comment
comment|/* B'00000101' */
end_comment

begin_define
define|#
directive|define
name|REJ_CONTROL
value|011
end_define

begin_comment
comment|/* B'00001001' */
end_comment

begin_define
define|#
directive|define
name|POLLOFF
value|0
end_define

begin_define
define|#
directive|define
name|POLLON
value|1
end_define

begin_comment
comment|/* Define Link State constants. */
end_comment

begin_define
define|#
directive|define
name|INIT
value|0
end_define

begin_define
define|#
directive|define
name|DM_SENT
value|1
end_define

begin_define
define|#
directive|define
name|SABM_SENT
value|2
end_define

begin_define
define|#
directive|define
name|ABM
value|3
end_define

begin_define
define|#
directive|define
name|WAIT_SABM
value|4
end_define

begin_define
define|#
directive|define
name|WAIT_UA
value|5
end_define

begin_define
define|#
directive|define
name|DISC_SENT
value|6
end_define

begin_define
define|#
directive|define
name|DISCONNECTED
value|7
end_define

begin_define
define|#
directive|define
name|MAXSTATE
value|8
end_define

begin_comment
comment|/* The following constants are used in a switch statement to process    frames read from the communications line. */
end_comment

begin_define
define|#
directive|define
name|SABM
value|0 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|DM
value|1 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|DISC
value|2 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|UA
value|3 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|FRMR
value|4 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|RR
value|5 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|RNR
value|6 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|REJ
value|7 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|IFRAME
value|8 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|ILLEGAL
value|9 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|T1
value|(3 * PR_SLOWHZ)
end_define

begin_comment
comment|/*  IFRAME TIMEOUT - 3 seconds */
end_comment

begin_define
define|#
directive|define
name|T3
value|(T1 / 2)
end_define

begin_comment
comment|/*  RR generate timeout - 1.5 seconds */
end_comment

begin_define
define|#
directive|define
name|N2
value|10
end_define

begin_define
define|#
directive|define
name|MODULUS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_WINDOW_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|Z
value|0
end_define

begin_define
define|#
directive|define
name|Y
value|1
end_define

begin_define
define|#
directive|define
name|X
value|2
end_define

begin_define
define|#
directive|define
name|W
value|3
end_define

begin_define
define|#
directive|define
name|A
value|4
end_define

begin_define
define|#
directive|define
name|TX
value|0
end_define

begin_define
define|#
directive|define
name|RX
value|1
end_define

begin_function_decl
name|bool
name|range_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|valid_nr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|hd_remove
parameter_list|()
function_decl|;
end_function_decl

end_unit

