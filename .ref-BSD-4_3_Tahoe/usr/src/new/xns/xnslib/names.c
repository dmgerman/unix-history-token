begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file implements functions for dealing with names in the XNS  * environment.  */
end_comment

begin_comment
comment|/*  $Log:	names.c,v $  * Revision 2.1  86/07/29  06:44:22  jqj  * Most code in this module is now superseded by ns_nameof() and ns_addr()  * routines, which are part of the standard libc in 4.3bsd.  *   * Revision 2.0  85/11/21  07:22:14  jqj  * 4.3BSD standard release  *   * Revision 1.2  85/10/21  12:58:41  root  * Gould version:  eliminate various uses of ns_netof(), which doesn't  * work on Gould.  *   * Revision 1.3  85/03/11  16:37:13  jqj  * Public alpha-test version, released 11 March 1985  *   * Revision 1.2  85/01/27  07:37:32  jqj  * finished but undebugged version  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: names.c,v 2.1 86/07/29 06:44:22 jqj Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for ns.h and socket.h */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* for ns.h */
end_comment

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_comment
comment|/* for XNS addresses */
end_comment

begin_escape
end_escape

begin_function
name|struct
name|ns_addr
modifier|*
name|getXNSaddr
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|static
name|struct
name|ns_addr
name|result
decl_stmt|;
specifier|extern
name|struct
name|ns_addr
name|ns_addr
parameter_list|()
function_decl|;
name|result
operator|=
name|ns_addr
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
operator|&
name|result
return|;
block|}
end_function

end_unit

