begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* imagesbr.h - include file for image subroutines */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/image/RCS/imagesbr.h,v 7.1 91/02/22 09:33:22 mrose Interim $  *  *  * $Log:	imagesbr.h,v $  * Revision 7.1  91/02/22  09:33:22  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:00:00  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GENERAL */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|recording
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|pgm_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AKA */
end_comment

begin_function_decl
name|void
name|init_aka
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DIRECTORY */
end_comment

begin_comment
comment|/* IMAGE */
end_comment

begin_struct
struct|struct
name|type_IMAGE_Image
block|{
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|struct
name|qbuf
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|type_IMAGE_Image
modifier|*
name|fetch_image
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ERRORS */
end_comment

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MISC */
end_comment

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

end_unit

