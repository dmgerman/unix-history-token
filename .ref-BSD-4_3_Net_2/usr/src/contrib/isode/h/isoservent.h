begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* isoservent.h - ISODE services database access routines */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/isoservent.h,v 7.1 91/02/22 09:24:45 mrose Interim $  *  *  * $Log:	isoservent.h,v $  * Revision 7.1  91/02/22  09:24:45  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:47  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISOSERVENT_
end_ifndef

begin_define
define|#
directive|define
name|_ISOSERVENT_
end_define

begin_struct
struct|struct
name|isoservent
block|{
name|char
modifier|*
name|is_entity
decl_stmt|;
comment|/* name of entity */
name|char
modifier|*
name|is_provider
decl_stmt|;
comment|/* name of service provider */
define|#
directive|define
name|ISSIZE
value|64
comment|/* xSAP selector/ID */
name|int
name|is_selectlen
decl_stmt|;
union|union
block|{
name|char
name|is_un_selector
index|[
name|ISSIZE
index|]
decl_stmt|;
name|unsigned
name|short
name|is_un_port
decl_stmt|;
block|}
name|un_is
union|;
define|#
directive|define
name|is_selector
value|un_is.is_un_selector
define|#
directive|define
name|is_port
value|un_is.is_un_port
name|char
modifier|*
modifier|*
name|is_vec
decl_stmt|;
comment|/* exec vector */
name|char
modifier|*
modifier|*
name|is_tail
decl_stmt|;
comment|/* next free slot in vector */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|setisoservent
argument_list|()
decl_stmt|,
name|endisoservent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|isoservent
modifier|*
name|getisoservent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isoservent
modifier|*
name|getisoserventbyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isoservent
modifier|*
name|getisoserventbyselector
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isoservent
modifier|*
name|getisoserventbyport
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

