begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ranlib.h 1.6 88/08/19 SMI; from UCB 4.1 83/05/03	*/
end_comment

begin_comment
comment|/*	$Id: ranlib.h,v 1.5 2005/11/01 02:35:15 sjg Exp $	*/
end_comment

begin_comment
comment|/*  * Structure of the __.SYMDEF table of contents for an archive.  * __.SYMDEF begins with a word giving the number of ranlib structures  * which immediately follow, and then continues with a string  * table consisting of a word giving the number of bytes of strings  * which follow and then the strings themselves.  * The ran_strx fields index the string table whose first byte is numbered 0.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IRIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__digital__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_ranlib_h
end_ifndef

begin_define
define|#
directive|define
name|_ranlib_h
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|RANLIBMAG
value|"!<arch>\n__.SYMDEF"
end_define

begin_comment
comment|/* archive file name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RANLIBMAG
value|"__.SYMDEF"
end_define

begin_comment
comment|/* archive file name */
end_comment

begin_define
define|#
directive|define
name|RANLIBSKEW
value|3
end_define

begin_comment
comment|/* creation time offset */
end_comment

begin_struct
struct|struct
name|ranlib
block|{
union|union
block|{
name|off_t
name|ran_strx
decl_stmt|;
comment|/* string table index of */
name|char
modifier|*
name|ran_name
decl_stmt|;
comment|/* symbol defined by */
block|}
name|ran_un
union|;
name|off_t
name|ran_off
decl_stmt|;
comment|/* library member at this offset */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_ranlib_h*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

