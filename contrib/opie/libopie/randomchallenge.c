begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* randomchallenge.c: The opierandomchallenge() library function.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1997 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.          History:          Modified by cmetz for OPIE 2.3. Add sha support. 	Modified by cmetz for OPIE 2.22. Don't include stdio.h. 	     Use opienewseed(). Don't include unneeded headers. 	Modified by cmetz for OPIE 2.2. Use FUNCTION declaration et al.              Changed use of gethostname() to uname(). Ifdefed around some              headers.         Created at NRL for OPIE 2.2 from opiesubr2.c */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|algids
index|[]
init|=
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|"sha1"
block|,
literal|"md4"
block|,
literal|"md5"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate a random challenge */
end_comment

begin_comment
comment|/* This could grow into quite a monster, really. Random is good enough for    most situations; it is certainly better than a fixed string */
end_comment

begin_decl_stmt
name|VOIDRET
name|opierandomchallenge
name|FUNCTION
argument_list|(
operator|(
name|prompt
operator|)
argument_list|,
name|char
operator|*
name|prompt
argument_list|)
block|{
name|char
name|buf
index|[
name|OPIE_SEED_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|opienewseed
argument_list|(
name|buf
argument_list|)
condition|)
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"ke4452"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|prompt
argument_list|,
literal|"otp-%s %d %s"
argument_list|,
name|algids
index|[
name|MDX
index|]
argument_list|,
operator|(
name|rand
argument_list|()
operator|%
literal|499
operator|)
operator|+
literal|1
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

