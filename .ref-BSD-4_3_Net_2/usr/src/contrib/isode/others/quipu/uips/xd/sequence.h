begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /f/osi/others/quipu/uips/xd/RCS/sequence.h,v 7.1 91/02/22 09:33:07 mrose Interim $ */
end_comment

begin_comment
comment|/*  $Log:	sequence.h,v $  * Revision 7.1  91/02/22  09:33:07  mrose  * Interim 6.8  *   * Revision 7.0  90/06/12  13:10:56  mrose  * *** empty log message ***  *   * Revision 1.5  90/04/26  10:22:47  emsrssn  * Installation fixed  *   *   * Revision 1.4  90/04/25  17:28:16  emsrssn  * Lint tidy up  *   *   * Revision 1.3  90/04/19  13:54:18  emsrssn  * keyboard accelerator now activates button highlight.  *   * search types available is dependent on current position  * to prevent unreasonable searches.  *   * the help popup changes automatically depending on the   * position of the cursor  *   * buttons remain a fixed size when the application is  * resized  *   * command line options are now handled properly  *   * logging added  *   * "reads" are now sorted to show mail address at top etc.  *   *   * Revision 1.2  90/03/09  15:57:35  emsrssn  * First public distribution  *   *   * Revision 1.1  90/03/08  13:18:48  emsrssn  * Initial revision  *   *  */
end_comment

begin_comment
comment|/* This file contains code to implement the list storage facilities  * in the modified widget program (renamed SD 5/1/90).  */
end_comment

begin_comment
comment|/*    This file was written by Damanjit Mahl @ Brunel University  *    on 31st October 1989 as part of the modifications made to   *    the Quipu X.500 widget interface written by Paul Sharpe  *    at GEC Research, Hirst Research Centre.  */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEQ
end_ifndef

begin_define
define|#
directive|define
name|SEQ
end_define

begin_include
include|#
directive|include
file|<strings.h>
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
name|d_seq
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
name|d_seq
modifier|*
name|next
decl_stmt|;
block|}
name|d_seq
operator|,
typedef|*
name|D_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDS
value|((D_seq) 0)
end_define

begin_function_decl
name|char
modifier|*
name|get_from_seq
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

