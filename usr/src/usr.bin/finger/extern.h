begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.3 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|tbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp buffer for anybody. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of people. */
end_comment

begin_decl_stmt
specifier|extern
name|DB
modifier|*
name|db
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Database. */
end_comment

begin_decl_stmt
name|void
name|enter_lastlog
name|__P
argument_list|(
operator|(
name|PERSON
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PERSON
modifier|*
name|enter_person
name|__P
argument_list|(
operator|(
expr|struct
name|passwd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enter_where
name|__P
argument_list|(
operator|(
expr|struct
name|utmp
operator|*
operator|,
name|PERSON
operator|*
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
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PERSON
modifier|*
name|find_person
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lflag_print
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|match
name|__P
argument_list|(
operator|(
expr|struct
name|passwd
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|netfinger
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PERSON
modifier|*
name|palloc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|prphone
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sflag_print
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

