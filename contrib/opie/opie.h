begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opie.h: Data structures and values for the OPIE authentication 	system that a program might need.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1997 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.  	History:  	Modified by cmetz for OPIE 2.31. Removed active attack protection. 	Modified by cmetz for OPIE 2.3. Renamed PTR to VOIDPTR. Added 		re-init key and extension file fields to struct opie. Added 		opie_ prefix on struct opie members. Added opie_flags field 		and definitions. Added more prototypes. Changed opiehash() 		prototype. 	Modified by cmetz for OPIE 2.22. Define __P correctly if this file 		is included in a third-party program. 	Modified by cmetz for OPIE 2.2. Re-did prototypes. Added FUNCTION                 definition et al. Multiple-include protection. Added struct 		utsname fake. Got rid of gethostname() cruft. Moved UINT4                 here. Provide for *seek whence values. Move MDx context here                 and unify. Re-did prototypes. 	Modified at NRL for OPIE 2.0. 	Written at Bellcore for the S/Key Version 1 software distribution 		(skey.h). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPIE_H
end_ifndef

begin_define
define|#
directive|define
name|_OPIE_H
value|1
end_define

begin_struct
struct|struct
name|opie
block|{
name|int
name|opie_flags
decl_stmt|;
name|char
name|opie_buf
index|[
literal|256
index|]
decl_stmt|;
name|char
modifier|*
name|opie_principal
decl_stmt|;
name|int
name|opie_n
decl_stmt|;
name|char
modifier|*
name|opie_seed
decl_stmt|;
name|char
modifier|*
name|opie_val
decl_stmt|;
name|long
name|opie_recstart
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__OPIE_FLAGS_RW
value|1
end_define

begin_define
define|#
directive|define
name|__OPIE_FLAGS_READ
value|2
end_define

begin_comment
comment|/* Minimum length of a secret password */
end_comment

begin_define
define|#
directive|define
name|OPIE_SECRET_MIN
value|10
end_define

begin_comment
comment|/* Maximum length of a secret password */
end_comment

begin_define
define|#
directive|define
name|OPIE_SECRET_MAX
value|127
end_define

begin_comment
comment|/* Minimum length of a seed */
end_comment

begin_define
define|#
directive|define
name|OPIE_SEED_MIN
value|5
end_define

begin_comment
comment|/* Maximum length of a seed */
end_comment

begin_define
define|#
directive|define
name|OPIE_SEED_MAX
value|16
end_define

begin_comment
comment|/* Maximum length of a challenge (otp-md? 9999 seed) */
end_comment

begin_define
define|#
directive|define
name|OPIE_CHALLENGE_MAX
value|(7+1+4+1+OPIE_SEED_MAX)
end_define

begin_comment
comment|/* Maximum length of a response that we allow */
end_comment

begin_define
define|#
directive|define
name|OPIE_RESPONSE_MAX
value|(9+1+19+1+9+OPIE_SEED_MAX+1+19+1+19+1+19)
end_define

begin_comment
comment|/* Maximum length of a principal (read: user name) */
end_comment

begin_define
define|#
directive|define
name|OPIE_PRINCIPAL_MAX
value|32
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|opieaccessfile
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
name|int
name|rdnets
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isaddr
name|__P
argument_list|(
operator|(
specifier|register
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiealways
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
name|char
modifier|*
name|opieatob8
name|__P
argument_list|(
operator|(
name|char
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
name|opiebackspace
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
name|char
modifier|*
name|opiebtoa8
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|opiebtoe
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|opiebtoh
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opieetob
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiechallenge
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiegenerator
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiegetsequence
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|opiehash
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiehtoi
name|__P
argument_list|(
operator|(
specifier|register
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiekeycrunch
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opielock
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
name|int
name|opielookup
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiepasscheck
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
name|opierandomchallenge
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
name|char
modifier|*
name|opieskipspace
name|__P
argument_list|(
operator|(
specifier|register
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|opiestripcrlf
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
name|int
name|opieverify
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opiepasswd
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|opiereadpass
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opielogin
name|__P
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|host
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__END_DECLS
if|#
directive|if
name|_OPIE
define|#
directive|define
name|VOIDPTR
value|void *
define|#
directive|define
name|VOIDRET
value|void
define|#
directive|define
name|NOARGS
value|void
define|#
directive|define
name|FUNCTION
parameter_list|(
name|arglist
parameter_list|,
name|args
parameter_list|)
value|(args)
define|#
directive|define
name|AND
value|,
define|#
directive|define
name|FUNCTION_NOARGS
value|()
define|#
directive|define
name|UINT4
value|u_int32_t
name|__BEGIN_DECLS
expr|struct
name|utmp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|__opiegetutmpentry
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|utmp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|EOF
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|__opieopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EOF */
end_comment

begin_decl_stmt
name|int
name|__opiereadrec
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__opiewriterec
name|__P
argument_list|(
operator|(
expr|struct
name|opie
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPIE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPIE_H */
end_comment

end_unit

