begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* options.h: Configuration options the end user might want to tweak.  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.         History:         Created by cmetz for OPIE 2.3 using the old Makefile.source as a                 guide. */
end_comment

begin_comment
comment|/*   Which hash should the OPIE server software use?    We strongly recommend that you use MD5. MD4 is faster, but less secure. If you are migrating from Bellcore S/Key version 1 and wish to use the existing key database, you must use MD4. In this case, you should consider ways to re-key your users using MD5. */
end_comment

begin_define
define|#
directive|define
name|MDX
value|5
end_define

begin_comment
comment|/* Use MD5 */
end_comment

begin_comment
comment|/* #define MDX    4 /* Use MD4 */
end_comment

begin_comment
comment|/*   Ask users to re-type their secret pass phrases?    Doing so helps catch typing mistakes, but some users find it annoying. */
end_comment

begin_comment
comment|/* #define RETYPE 1 /* Ask users to re-type their secret pass phrases */
end_comment

begin_define
define|#
directive|define
name|RETYPE
value|0
end_define

begin_comment
comment|/* Don't ask users to re-type their secret pass phrases */
end_comment

begin_comment
comment|/*   Generater lock files to serialize OTP logins?    There is a potential race attack on OTP when more than one session can respond to the same challenge at the same time. This locking only allows one session at a time per principal (user) to attempt to log in using OTP. The locking, however, creates a denial-of-service attack as a trade-off and can be annoying if you have a legitimate need for two sessions to attempt to authenticate as the same principal at the same time. */
end_comment

begin_define
define|#
directive|define
name|USER_LOCKING
value|1
end_define

begin_comment
comment|/* Serialize OTP challenges for a principal */
end_comment

begin_comment
comment|/* #define USER_LOCKING 0 /* Don't serialize OTP challenges */
end_comment

begin_comment
comment|/*   Should su(8) refuse to switch to disabled accounts?    Traditionally, su(8) can switch to any account, even if it is disabled. In most systems, there is no legitimate need for this capability and it can create security problems. */
end_comment

begin_define
define|#
directive|define
name|SU_STAR_CHECK
value|1
end_define

begin_comment
comment|/* Refuse to switch to disabled accounts */
end_comment

begin_comment
comment|/* #define SU_STAR_CHECK 0 /* Allow switching to disabled accounts */
end_comment

begin_comment
comment|/*   Should OPIE use more informative prompts?    The new-style, more informative prompts better indicate to the user what is being asked for. However, some automated login scripts depend on the wording of some prompts and will fail if you change them. */
end_comment

begin_define
define|#
directive|define
name|NEW_PROMPTS
value|1
end_define

begin_comment
comment|/* Use the more informative prompts */
end_comment

begin_comment
comment|/* #define NEW_PROMPTS 0 /* Use the more compatible prompts */
end_comment

begin_comment
comment|/*   Should the user be allowed to override "insecure" terminal checks?    The "insecure" terminal checks are designed to help make it more clear to users that they shouldn't disclose their secret over insecure lines by refusing to accept the secret directly. These checks aren't perfect and sometimes will cause OPIE to refuse to work when it really should. Allowing users to override the terminal checks also helps the process of creating OTP sequences for users. However, allowing users to override the terminal checks also allows users to shoot themselves in the foot, which isn't usually what you want. */
end_comment

begin_define
define|#
directive|define
name|INSECURE_OVERRIDE
value|0
end_define

begin_comment
comment|/* Don't allow users to override the checks */
end_comment

begin_comment
comment|/* #define INSECURE_OVERRIDE 1 /* Allow users to override the checks */
end_comment

end_unit

