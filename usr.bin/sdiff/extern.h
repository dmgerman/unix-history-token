begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: extern.h,v 1.5 2009/06/07 13:29:50 ray Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Written by Raymond Lai<ray@cyth.net>.  * Public domain.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file to save changes to */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tmpdir
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|eparse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

