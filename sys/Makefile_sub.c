begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**/
end_comment

begin_empty
empty|#	From: /usr/src/sys/Makefile_sub.c		V1.4<stacey@guug.de>
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	$Id$
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	Do not edit Makefile_sub, (produced from Makefile_sub.c by Makefile).
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	Copyright: Julian Stacey, Munich, October 1993,
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	Free Software - No Liability Accepted.
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	This Makefile_sub.c is not known as Makefile.c for 2 reasons:
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#		recursive make depend might zap Makefile
end_empty

begin_comment
comment|/**/
end_comment

begin_empty
empty|#		general cleaning shells might also zap Makefile
end_empty

begin_label
name|all
label|:
end_label

begin_expr_stmt
unit|@
name|echo
name|Subsidiary
name|makefile
name|has
name|been
name|erroneously
name|called
name|directly
operator|.
expr|@
name|echo
name|It
name|should
name|only
name|be
name|called
name|from
name|Makefile
operator|.
name|exit
literal|1
operator|/
name|usr
operator|/
name|src
operator|/
name|sys
operator|/
name|impossible_command
comment|/**/
empty|# Next label recreates a compile tree if:
comment|/**/
empty|#	- The config description file changes,
comment|/**/
empty|#		for example if /sys/compile/GENERICAH/Makefile is older than
comment|/**/
empty|#		/sys/i386/conf/GENERICAH, /sys/compile/GENERICAH
comment|/* is rebuilt. /**/
empty|#	- Changes occur to i386/conf/Makefile.i386 devices.i386 files.i386.
comment|/**/
empty|#	- A new source tree is imported.  This might not be strictly necessary,
comment|/**/
empty|#	  If the Makefile know of Every dependency, but as the kernel
comment|/**/
empty|#	  evolves rapidly, it seems a harmless safety net.
comment|/**/
empty|# 	- Changes occur to Makefile or Makefile_sub.
name|CONFIG_TREE_TEST
operator|:
name|$
block|{
name|MACHINE
block|}
operator|/
name|conf
operator|/
name|CONFIG_NAME
expr|\
name|$
block|{
name|MACHINE
block|}
operator|/
name|conf
operator|/
name|Makefile
operator|.
name|$
block|{
name|MACHINE
block|}
expr|\
name|$
block|{
name|MACHINE
block|}
operator|/
name|conf
operator|/
name|devices
operator|.
name|$
block|{
name|MACHINE
block|}
expr|\
name|$
block|{
name|MACHINE
block|}
operator|/
name|conf
operator|/
name|files
operator|.
name|$
block|{
name|MACHINE
block|}
expr|\
operator|.
name|config
operator|.
name|import
expr|\
name|Makefile
name|MAKEFILE_KERNEL
comment|/**/
operator|.
expr|if
name|defined
argument_list|(
name|DEBUG_SYS
argument_list|)
expr|@
name|echo
operator|-
name|n
name|Configuring
name|a
name|kernel
name|compilation
name|tree
end_expr_stmt

begin_for
for|for CONFIG_NAME 	@echo -n " as defined in " 	@echo $
block|{
name|MACHINE
block|}
end_for

begin_expr_stmt
operator|/
name|conf
operator|/
name|CONFIG_NAME
operator|.
comment|/**/
expr|.
name|endif
name|cd
name|$
block|{
name|MACHINE
block|}
operator|/
name|conf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|config
name|CONFIG_NAME
comment|/**/
empty|#	# If config fails, no error code is seen here unfortunately.
comment|/**/
empty|#	# This was reccomended for flexfax, may not be necessary now:
comment|/**/
empty|#	#	-rm -f compile/CONFIG_NAME/fifo.h compile/CONFIG_NAME/\*.o
comment|/**/
operator|.
expr|if
name|defined
argument_list|(
argument|LOAD_ADDRESS
argument_list|)
name|cd
name|compile
operator|/
name|CONFIG_NAME
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|make
name|LOAD_ADDRESS
init|=
name|$
block|{
name|LOAD_ADDRESS
block|}
name|depend
comment|/**/
operator|.
expr|else
name|cd
name|compile
operator|/
name|CONFIG_NAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|make
name|depend
comment|/**/
operator|.
name|endif
comment|/**/
operator|.
name|config
operator|.
name|import
range|:
name|touch
name|$
expr|@
end_decl_stmt

begin_comment
comment|/**/
end_comment

begin_empty
empty|#	End of Makefile_sub.c
end_empty

end_unit

