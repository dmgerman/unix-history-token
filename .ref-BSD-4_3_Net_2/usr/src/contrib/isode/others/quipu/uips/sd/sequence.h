begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /f/osi/others/quipu/uips/sd/RCS/sequence.h,v 7.2 91/02/22 09:32:25 mrose Interim $  */
end_comment

begin_comment
comment|/* This file contains code to implement the list storage facilities  * in the modified widget program (renamed SD 5/1/90).  */
end_comment

begin_comment
comment|/*    This file was written by Damanjit Mahl @ Brunel University  *    as part of the modifications made to   *    the Quipu X.500 widget interface written by Paul Sharpe  *    at GEC Research, Hirst Research Centre.  */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRINGSEQ
end_ifndef

begin_define
define|#
directive|define
name|STRINGSEQ
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|QUIPU_MALLOC
end_ifdef

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|smalloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|string_seq
block|{
name|char
modifier|*
name|dname
decl_stmt|;
name|unsigned
name|strlen
decl_stmt|;
name|int
name|seq_num
decl_stmt|;
name|struct
name|string_seq
modifier|*
name|next
decl_stmt|;
block|}
name|string_seq
operator|,
typedef|*
name|str_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDS
value|((str_seq) 0)
end_define

begin_function_decl
name|char
modifier|*
name|get_from_seq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|free_seq
argument_list|()
decl_stmt|,
name|add_seq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

