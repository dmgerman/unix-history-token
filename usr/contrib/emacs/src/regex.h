begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures callers pass the regex library.    Copyright (C) 1985 Richard M. Stallman  This program is distributed in the hope that it will be useful, but without any warranty.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.     Permission is granted to anyone to distribute verbatim copies    of this program's source code as received, in any medium, provided that    the copyright notice, the nonwarraty notice above    and this permission notice are preserved,    and that the distributor grants the recipient all rights    for further redistribution as permitted by this notice,    and informs him of these rights.     Permission is granted to distribute modified versions of this    program's source code, or of portions of it, under the above    conditions, plus the conditions that all changed files carry    prominent notices stating who last changed them and that the    derived material, including anything packaged together with it and    conceptually functioning as a modification of it rather than an    application of it, is in its entirety subject to a permission    notice identical to this one.     Permission is granted to distribute this program (verbatim or    as modified) in compiled or executable form, provided verbatim    redistribution is permitted as stated above for source code, and     A.  it is accompanied by the corresponding machine-readable       source code, under the above conditions, or     B.  it is accompanied by a written offer, with no time limit,       to distribute the corresponding machine-readable source code,       under the above conditions, to any one, in return for reimbursement       of the cost of distribution.   Verbatim redistribution of the       written offer must be permitted.  Or,     C.  it is distributed by someone who received only the       compiled or executable form, and is accompanied by a copy of the       written offer of source code which he received along with it.     Permission is granted to distribute this program (verbatim or as modified)    in executable form as part of a larger system provided that the source    code for this program, including any modifications used,    is also distributed or offered as stated in the preceding paragraph.  In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RE_NREGS
end_ifndef

begin_define
define|#
directive|define
name|RE_NREGS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This data structure is used to represent a compiled pattern. */
end_comment

begin_struct
struct|struct
name|re_pattern_buffer
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Space holding the compiled pattern commands. */
name|int
name|allocated
decl_stmt|;
comment|/* Size of space that  buffer  points to */
name|int
name|used
decl_stmt|;
comment|/* Length of portion of buffer actually occupied */
name|char
modifier|*
name|fastmap
decl_stmt|;
comment|/* Pointer to fastmap, if any, or zero if none. */
comment|/* re_search uses the fastmap, if there is one, 			   to skip quickly over totally implausible characters */
name|char
modifier|*
name|translate
decl_stmt|;
comment|/* Translate table to apply to all characters before comparing. 			   Or zero for no translation. 			   The translation is applied to a pattern when it is compiled 			   and to data when it is matched. */
name|char
name|fastmap_accurate
decl_stmt|;
comment|/* Set to zero when a new pattern is stored, 			   set to one when the fastmap is updated from it. */
name|char
name|can_be_null
decl_stmt|;
comment|/* Set to one by compiling fastmap 			   if this pattern might match the null string. 			   It does not necessarily match the null string 			   in that case, but if this is zero, it cannot.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to store "register" contents data in.     Pass the address of such a structure as an argument to re_match, etc.,    if you want this information back.     start[i] and end[i] record the string matched by \( ... \) grouping i,    for i from 1 to RE_NREGS - 1.    start[0] and end[0] record the entire string matched. */
end_comment

begin_struct
struct|struct
name|re_registers
block|{
name|int
name|start
index|[
name|RE_NREGS
index|]
decl_stmt|;
name|int
name|end
index|[
name|RE_NREGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|char
modifier|*
name|re_compile_pattern
parameter_list|()
function_decl|;
end_function_decl

end_unit

