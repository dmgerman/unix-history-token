begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2000, 2001 Free Software Foundation, Inc.      Written by Werner Lemberg (wl@gnu.org)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/*    This file has to be included from within lib.h instead of getopt.h    to avoid problems with picky C++ compilers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GROFF_GETOPT_H
end_ifndef

begin_define
define|#
directive|define
name|_GROFF_GETOPT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
specifier|extern
name|int
name|optind
decl_stmt|;
specifier|extern
name|int
name|opterr
decl_stmt|;
specifier|extern
name|int
name|optopt
decl_stmt|;
struct|struct
name|option
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|has_arg
decl_stmt|;
name|int
modifier|*
name|flag
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|no_argument
value|0
define|#
directive|define
name|required_argument
value|1
define|#
directive|define
name|optional_argument
value|2
specifier|extern
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
comment|// __argc
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
comment|// __argv
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|// __shortopts
specifier|extern
name|int
name|getopt_long
parameter_list|(
name|int
parameter_list|,
comment|// __argc
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
comment|// __argv
specifier|const
name|char
modifier|*
parameter_list|,
comment|// __shortopts
specifier|const
name|struct
name|option
modifier|*
parameter_list|,
comment|// __longopts
name|int
modifier|*
parameter_list|)
function_decl|;
comment|// __longind
specifier|extern
name|int
name|getopt_long_only
parameter_list|(
name|int
parameter_list|,
comment|// __argc
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
comment|// __argv
specifier|const
name|char
modifier|*
parameter_list|,
comment|// __shortopts
specifier|const
name|struct
name|option
modifier|*
parameter_list|,
comment|// __longopts
name|int
modifier|*
parameter_list|)
function_decl|;
comment|// __longind
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GROFF_GETOPT_H */
end_comment

end_unit

