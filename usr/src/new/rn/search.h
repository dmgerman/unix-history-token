begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: search.h,v 4.3 85/05/01 11:50:46 lwall Exp $  *  * $Log:	search.h,v $  * Revision 4.3  85/05/01  11:50:46  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NBRA
end_ifndef

begin_define
define|#
directive|define
name|NBRA
value|10
end_define

begin_comment
comment|/* the maximum number of meta-brackets in an 				   RE -- \( \) */
end_comment

begin_define
define|#
directive|define
name|NALTS
value|10
end_define

begin_comment
comment|/* the maximum number of \|'s */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|expbuf
decl_stmt|;
comment|/* The compiled search string */
name|int
name|eblen
decl_stmt|;
comment|/* Length of above buffer */
name|char
modifier|*
name|alternatives
index|[
name|NALTS
index|]
decl_stmt|;
comment|/* The list of \| seperated alternatives */
name|char
modifier|*
name|braslist
index|[
name|NBRA
index|]
decl_stmt|;
comment|/* RE meta-bracket start list */
name|char
modifier|*
name|braelist
index|[
name|NBRA
index|]
decl_stmt|;
comment|/* RE meta-bracket end list */
name|char
modifier|*
name|brastr
decl_stmt|;
comment|/* saved match string after execute() */
name|char
name|nbra
decl_stmt|;
comment|/* The number of meta-brackets int the most 				   recenlty compiled RE */
name|bool
name|do_folding
decl_stmt|;
comment|/* fold upper and lower case? */
block|}
name|COMPEX
typedef|;
end_typedef

begin_function_decl
name|void
name|search_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_compex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_compex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getbracket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|case_fold
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|compile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|grow_eb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|execute
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|advance
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|backref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cclass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

