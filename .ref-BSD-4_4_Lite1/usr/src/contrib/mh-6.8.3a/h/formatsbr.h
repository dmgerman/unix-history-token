begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* formatsbr.h - definitions for fmtscan () */
end_comment

begin_comment
comment|/* $Id: formatsbr.h,v 1.1 1992/01/23 23:14:54 jromine Exp $ */
end_comment

begin_comment
comment|/*  * This structure describes an "interesting" component.  It holds  * the name& text from the component (if found) and one piece of  * auxilary info.  The structure for a particular component is located  * by hashing the name and using it as an index into the ptr array  * "wantcomp".  All format entries that reference a particular component  * point to its comp struct (so we only have to do component specific  * processing once.  e.g., parse an address.).  */
end_comment

begin_struct
struct|struct
name|comp
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* component name (in lower case) */
name|struct
name|comp
modifier|*
name|c_next
decl_stmt|;
comment|/* hash chain linkage */
name|char
modifier|*
name|c_text
decl_stmt|;
comment|/* component text (if found) */
name|short
name|c_flags
decl_stmt|;
comment|/* misc. flags (from formatsbr) */
name|short
name|c_type
decl_stmt|;
comment|/* type info (from fmtcompile) */
union|union
block|{
name|struct
name|tws
modifier|*
name|c_u_tws
decl_stmt|;
name|struct
name|mailname
modifier|*
name|c_u_mn
decl_stmt|;
block|}
name|c_un
union|;
define|#
directive|define
name|c_tws
value|c_un.c_u_tws
define|#
directive|define
name|c_mn
value|c_un.c_u_mn
block|}
struct|;
end_struct

begin_comment
comment|/* c_type bits */
end_comment

begin_define
define|#
directive|define
name|CT_ADDR
value|1
end_define

begin_comment
comment|/* referenced as address */
end_comment

begin_define
define|#
directive|define
name|CT_DATE
value|2
end_define

begin_comment
comment|/* referenced as date */
end_comment

begin_define
define|#
directive|define
name|CT_MYMBOX
value|4
end_define

begin_comment
comment|/* "mymbox" test being done */
end_comment

begin_define
define|#
directive|define
name|CT_ADDRPARSE
value|8
end_define

begin_comment
comment|/* address parse being done */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fmt_norm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|comp
modifier|*
name|wantcomp
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for deciding if a 				 * component is "interesting" */
end_comment

begin_comment
comment|/*   * Hash function for component name.  The function should be  * case independent and probably shouldn't involve a routine  * call.  This function is pretty good but will not work on  * single character component names.    */
end_comment

begin_define
define|#
directive|define
name|CHASH
parameter_list|(
name|nm
parameter_list|)
value|(((((nm)[0]) - ((nm)[1]))& 0x1f) + (((nm)[2])& 0x5f))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GOULD_PN
end_ifdef

begin_comment
comment|/* bug in the Gould PowerNode compiler: need a local pointer to name... */
end_comment

begin_define
define|#
directive|define
name|FINDCOMP
parameter_list|(
name|comp
parameter_list|,
name|name1
parameter_list|)
define|\
value|{ \ 	char *name = (name1); \ 	for (comp = wantcomp[CHASH(name)]; \ 		comp&& strcmp(comp->c_name,name); \ 		comp = comp->c_next) ; \ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FINDCOMP
parameter_list|(
name|comp
parameter_list|,
name|name
parameter_list|)
define|\
value|for (comp = wantcomp[CHASH(name)]; \ 		     comp&& strcmp(comp->c_name,name); \ 		     comp = comp->c_next) ;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This structure defines one formatting instruction.  */
end_comment

begin_struct
struct|struct
name|format
block|{
name|unsigned
name|char
name|f_type
decl_stmt|;
name|char
name|f_fill
decl_stmt|;
name|short
name|f_width
decl_stmt|;
comment|/* output field width */
define|#
directive|define
name|f_skip
value|f_width
comment|/* instr to skip (false "if") */
union|union
block|{
name|struct
name|comp
modifier|*
name|f_u_comp
decl_stmt|;
comment|/* associated component */
name|char
modifier|*
name|f_u_text
decl_stmt|;
comment|/* literal text */
name|char
name|f_u_char
decl_stmt|;
comment|/* literal character */
name|int
name|f_u_value
decl_stmt|;
comment|/* literal value */
block|}
name|f_un
union|;
define|#
directive|define
name|f_comp
value|f_un.f_u_comp
define|#
directive|define
name|f_text
value|f_un.f_u_text
define|#
directive|define
name|f_char
value|f_un.f_u_char
define|#
directive|define
name|f_value
value|f_un.f_u_value
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|format
modifier|*
name|fmtscan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|new_fs
parameter_list|()
function_decl|;
end_function_decl

end_unit

