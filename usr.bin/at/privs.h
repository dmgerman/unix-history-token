begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  privs.h - header for privileged operations  *  Copyright (C) 1993  Thomas Koenig  *  *  This program is free software; you can redistribute it and/or modify  *  it under the terms of the GNU General Public License as published by  *  the Free Software Foundation; either version 2 of the License, or  *  (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PRIVS_H
end_ifndef

begin_define
define|#
directive|define
name|_PRIVS_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_USE_BSD
end_ifndef

begin_define
define|#
directive|define
name|_USE_BSD
value|1
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_undef
undef|#
directive|undef
name|_USE_BSD
end_undef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Relinquish privileges temporarily for a setuid or setgid program  * with the option of getting them back later.  This is done by swapping  * the real and effective userid BSD style.  Call RELINQUISH_PRIVS once  * at the beginning of the main program.  This will cause all operatons  * to be executed with the real userid.  When you need the privileges  * of the setuid/setgid invocation, call PRIV_START; when you no longer  * need it, call PRIV_END.  Note that it is an error to call PRIV_START  * and not PRIV_END within the same function.  *  * Use RELINQUISH_PRIVS_ROOT(a,b) if your program started out running  * as root, and you want to drop back the effective userid to a  * and the effective group id to b, with the option to get them back  * later.  *  * If you no longer need root privileges, but those of some other  * userid/groupid, you can call REDUCE_PRIV(a,b) when your effective  * is the user's.  *  * Problems: Do not use return between PRIV_START and PRIV_END; this  * will cause the program to continue running in an unprivileged  * state.  *  * It is NOT safe to call exec(), system() or popen() with a user-  * supplied program (i.e. without carefully checking PATH and any  * library load paths) with relinquished privileges; the called program  * can aquire them just as easily.  Set both effective and real userid  * to the real userid before calling any of them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAIN
end_ifndef

begin_decl_stmt
specifier|extern
endif|#
directive|endif
name|uid_t
name|real_uid
decl_stmt|,
name|effective_uid
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAIN
end_ifndef

begin_decl_stmt
specifier|extern
endif|#
directive|endif
name|gid_t
name|real_gid
decl_stmt|,
name|effective_gid
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RELINQUISH_PRIVS
value|{ \ 			      real_uid = getuid(); \ 			      effective_uid = geteuid(); \ 			      real_gid = getgid(); \ 			      effective_gid = getegid(); \ 			      setreuid(effective_uid, real_uid); \ 			      setregid(effective_gid, real_gid); \ 		          }
end_define

begin_define
define|#
directive|define
name|RELINQUISH_PRIVS_ROOT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ \ 			      real_uid = (a); \ 			      effective_uid = geteuid(); \ 			      real_gid = (b); \ 			      effective_gid = getegid(); \ 			      setreuid(effective_uid, real_uid); \ 			      setregid(effective_gid, real_gid); \ 		          }
end_define

begin_define
define|#
directive|define
name|PRIV_START
value|{\ 		    setreuid(real_uid, effective_uid); \ 		    setregid(real_gid, effective_gid);
end_define

begin_define
define|#
directive|define
name|PRIV_END
define|\
value|setreuid(effective_uid, real_uid); \ 		    setregid(effective_gid, real_gid); \ 		    }
end_define

begin_define
define|#
directive|define
name|REDUCE_PRIV
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{\ 			setreuid(real_uid, effective_uid); \ 			setregid(real_gid, effective_gid); \ 			effective_uid = (a); \ 			effective_gid = (b); \ 			setregid(effective_gid, real_gid); \ 			setreuid(effective_uid, real_uid); \ 		    }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

