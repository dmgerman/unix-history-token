begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	gettytab.h	4.1	83/07/06	*/
end_comment

begin_comment
comment|/*  * Getty description definitions.  */
end_comment

begin_struct
struct|struct
name|gettystrs
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup in gettytab */
name|char
modifier|*
name|defalt
decl_stmt|;
comment|/* value we find by looking in defaults */
name|char
modifier|*
name|value
decl_stmt|;
comment|/* value that we find there */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gettynums
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup */
name|long
name|defalt
decl_stmt|;
comment|/* number we find in defaults */
name|long
name|value
decl_stmt|;
comment|/* number we find there */
name|int
name|set
decl_stmt|;
comment|/* we actually got this one */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gettyflags
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup */
name|char
name|invrt
decl_stmt|;
comment|/* name existing in gettytab --> false */
name|char
name|defalt
decl_stmt|;
comment|/* true/false in defaults */
name|char
name|value
decl_stmt|;
comment|/* true/false flag */
name|char
name|set
decl_stmt|;
comment|/* we found it */
block|}
struct|;
end_struct

begin_comment
comment|/*  * String values.  */
end_comment

begin_define
define|#
directive|define
name|NX
value|gettystrs[0].value
end_define

begin_define
define|#
directive|define
name|CL
value|gettystrs[1].value
end_define

begin_define
define|#
directive|define
name|IM
value|gettystrs[2].value
end_define

begin_define
define|#
directive|define
name|LM
value|gettystrs[3].value
end_define

begin_define
define|#
directive|define
name|ER
value|gettystrs[4].value
end_define

begin_define
define|#
directive|define
name|KL
value|gettystrs[5].value
end_define

begin_define
define|#
directive|define
name|ET
value|gettystrs[6].value
end_define

begin_define
define|#
directive|define
name|PC
value|gettystrs[7].value
end_define

begin_define
define|#
directive|define
name|TT
value|gettystrs[8].value
end_define

begin_define
define|#
directive|define
name|EV
value|gettystrs[9].value
end_define

begin_define
define|#
directive|define
name|LO
value|gettystrs[10].value
end_define

begin_define
define|#
directive|define
name|HN
value|gettystrs[11].value
end_define

begin_define
define|#
directive|define
name|HE
value|gettystrs[12].value
end_define

begin_define
define|#
directive|define
name|IN
value|gettystrs[13].value
end_define

begin_define
define|#
directive|define
name|QU
value|gettystrs[14].value
end_define

begin_define
define|#
directive|define
name|XN
value|gettystrs[15].value
end_define

begin_define
define|#
directive|define
name|XF
value|gettystrs[16].value
end_define

begin_define
define|#
directive|define
name|BK
value|gettystrs[17].value
end_define

begin_define
define|#
directive|define
name|SU
value|gettystrs[18].value
end_define

begin_define
define|#
directive|define
name|DS
value|gettystrs[19].value
end_define

begin_define
define|#
directive|define
name|RP
value|gettystrs[20].value
end_define

begin_define
define|#
directive|define
name|FL
value|gettystrs[21].value
end_define

begin_define
define|#
directive|define
name|WE
value|gettystrs[22].value
end_define

begin_define
define|#
directive|define
name|LN
value|gettystrs[23].value
end_define

begin_comment
comment|/*  * Numeric definitions.  */
end_comment

begin_define
define|#
directive|define
name|IS
value|gettynums[0].value
end_define

begin_define
define|#
directive|define
name|OS
value|gettynums[1].value
end_define

begin_define
define|#
directive|define
name|SP
value|gettynums[2].value
end_define

begin_define
define|#
directive|define
name|ND
value|gettynums[3].value
end_define

begin_define
define|#
directive|define
name|CD
value|gettynums[4].value
end_define

begin_define
define|#
directive|define
name|TD
value|gettynums[5].value
end_define

begin_define
define|#
directive|define
name|FD
value|gettynums[6].value
end_define

begin_define
define|#
directive|define
name|BD
value|gettynums[7].value
end_define

begin_define
define|#
directive|define
name|TO
value|gettynums[8].value
end_define

begin_define
define|#
directive|define
name|F0
value|gettynums[9].value
end_define

begin_define
define|#
directive|define
name|F0set
value|gettynums[9].set
end_define

begin_define
define|#
directive|define
name|F1
value|gettynums[10].value
end_define

begin_define
define|#
directive|define
name|F1set
value|gettynums[10].set
end_define

begin_define
define|#
directive|define
name|F2
value|gettynums[11].value
end_define

begin_define
define|#
directive|define
name|F2set
value|gettynums[11].set
end_define

begin_comment
comment|/*  * Boolean values.  */
end_comment

begin_define
define|#
directive|define
name|HT
value|gettyflags[0].value
end_define

begin_define
define|#
directive|define
name|NL
value|gettyflags[1].value
end_define

begin_define
define|#
directive|define
name|EP
value|gettyflags[2].value
end_define

begin_define
define|#
directive|define
name|OP
value|gettyflags[3].value
end_define

begin_define
define|#
directive|define
name|AP
value|gettyflags[4].value
end_define

begin_define
define|#
directive|define
name|EC
value|gettyflags[5].value
end_define

begin_define
define|#
directive|define
name|CO
value|gettyflags[6].value
end_define

begin_define
define|#
directive|define
name|CB
value|gettyflags[7].value
end_define

begin_define
define|#
directive|define
name|CK
value|gettyflags[8].value
end_define

begin_define
define|#
directive|define
name|CE
value|gettyflags[9].value
end_define

begin_define
define|#
directive|define
name|PE
value|gettyflags[10].value
end_define

begin_define
define|#
directive|define
name|RW
value|gettyflags[11].value
end_define

begin_define
define|#
directive|define
name|XC
value|gettyflags[12].value
end_define

begin_define
define|#
directive|define
name|LC
value|gettyflags[13].value
end_define

begin_define
define|#
directive|define
name|UC
value|gettyflags[14].value
end_define

begin_define
define|#
directive|define
name|IG
value|gettyflags[15].value
end_define

begin_define
define|#
directive|define
name|PS
value|gettyflags[16].value
end_define

begin_define
define|#
directive|define
name|HC
value|gettyflags[17].value
end_define

begin_function_decl
name|int
name|getent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|getnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getflag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getstr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|gettyflags
name|gettyflags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gettynums
name|gettynums
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gettystrs
name|gettystrs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hopcount
decl_stmt|;
end_decl_stmt

end_unit

