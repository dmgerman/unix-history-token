begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.5 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|p_end
decl_stmt|;
comment|/* pointer to NULL at end of path */
name|char
modifier|*
name|target_end
decl_stmt|;
comment|/* pointer to end of target base */
name|char
name|p_path
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* pointer to the start of a path */
block|}
name|PATH_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
specifier|extern
name|PATH_T
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iflag
decl_stmt|,
name|pflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uid_t
name|myuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exit_val
decl_stmt|,
name|myumask
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|copy_fifo
name|__P
argument_list|(
operator|(
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_file
name|__P
argument_list|(
operator|(
name|FTSENT
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_link
name|__P
argument_list|(
operator|(
name|FTSENT
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_special
name|__P
argument_list|(
operator|(
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|err
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setfile
name|__P
argument_list|(
operator|(
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

