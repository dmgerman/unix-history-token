begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* photo.h - */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/photo.h,v 7.1 91/02/22 09:26:03 mrose Interim $  *  *  * $Log:	photo.h,v $  * Revision 7.1  91/02/22  09:26:03  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:42  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|length
decl_stmt|;
comment|/* number of bits in the pattern  */
name|short
name|pattern
decl_stmt|;
comment|/* the bit pattern 						     (starting at bit 13) */
block|}
name|code_word
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|code_word
name|make
decl_stmt|,
comment|/* make up code */
comment|/* if make.length  = 0  then there 							 is no make up code */
name|term
decl_stmt|;
comment|/* terminal code */
block|}
name|full_code
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|pos
decl_stmt|;
comment|/* pointer into the string */
name|int
modifier|*
name|run_top
decl_stmt|;
comment|/* run length pointer */
name|int
modifier|*
name|run_pos
decl_stmt|;
comment|/* pointer to above */
name|unsigned
name|char
name|mask
decl_stmt|;
comment|/* mask to get at one bit of the string */
name|char
modifier|*
name|dbuf_top
decl_stmt|;
name|char
modifier|*
name|dbuf
decl_stmt|;
block|}
name|bit_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|r_type
decl_stmt|;
comment|/* descibes type of run */
name|int
name|run_length
decl_stmt|;
comment|/* a run_length         */
block|}
name|run_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nd
block|{
name|char
name|n_type
decl_stmt|;
comment|/* describe the type of node */
name|struct
name|nd
modifier|*
name|one
decl_stmt|;
comment|/* one branch */
name|struct
name|nd
modifier|*
name|zero
decl_stmt|;
comment|/* zero branch */
name|int
name|value
decl_stmt|;
comment|/* value arrived at */
block|}
name|node
typedef|;
end_typedef

begin_comment
comment|/* now some constant definitions */
end_comment

begin_define
define|#
directive|define
name|MSB_MASK
value|010000
end_define

begin_comment
comment|/* octal. Mask to get at first bit 						of code_word  pattern  */
end_comment

begin_define
define|#
directive|define
name|BIT_MASK
value|0x80
end_define

begin_comment
comment|/* i.e. set bit 8 of a char */
end_comment

begin_define
define|#
directive|define
name|WHITE
value|0
end_define

begin_define
define|#
directive|define
name|WT_TERM
value|0
end_define

begin_define
define|#
directive|define
name|BLACK
value|1
end_define

begin_define
define|#
directive|define
name|BL_TERM
value|1
end_define

begin_define
define|#
directive|define
name|MAKE
value|2
end_define

begin_define
define|#
directive|define
name|EOLN
value|127
end_define

begin_define
define|#
directive|define
name|INTERNAL
value|7
end_define

begin_define
define|#
directive|define
name|P
value|1
end_define

begin_define
define|#
directive|define
name|H
value|2
end_define

begin_define
define|#
directive|define
name|V0
value|6
end_define

begin_define
define|#
directive|define
name|VR1
value|7
end_define

begin_define
define|#
directive|define
name|VR2
value|8
end_define

begin_define
define|#
directive|define
name|VR3
value|9
end_define

begin_define
define|#
directive|define
name|VL1
value|5
end_define

begin_define
define|#
directive|define
name|VL2
value|4
end_define

begin_define
define|#
directive|define
name|VL3
value|3
end_define

begin_define
define|#
directive|define
name|BUFLEN
value|75000
end_define

begin_define
define|#
directive|define
name|LINEBUF
value|4096
end_define

begin_define
define|#
directive|define
name|FIXED_OFFSET
value|6
end_define

begin_function_decl
name|full_code
name|get_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|get_bit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|node
modifier|*
name|get_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|run_type
name|next_run
parameter_list|()
function_decl|;
end_function_decl

end_unit

