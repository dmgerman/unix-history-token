begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Defs for interface to demanglers.    Copyright 1992, 1993, 1994, 1995, 1996, 1997, 1998, 2000    Free Software Foundation, Inc.        This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEMANGLE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEMANGLE_H
end_define

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_comment
comment|/* Options passed to cplus_demangle (in 2nd parameter). */
end_comment

begin_define
define|#
directive|define
name|DMGL_NO_OPTS
value|0
end_define

begin_comment
comment|/* For readability... */
end_comment

begin_define
define|#
directive|define
name|DMGL_PARAMS
value|(1<< 0)
end_define

begin_comment
comment|/* Include function args */
end_comment

begin_define
define|#
directive|define
name|DMGL_ANSI
value|(1<< 1)
end_define

begin_comment
comment|/* Include const, volatile, etc */
end_comment

begin_define
define|#
directive|define
name|DMGL_JAVA
value|(1<< 2)
end_define

begin_comment
comment|/* Demangle as Java rather than C++. */
end_comment

begin_define
define|#
directive|define
name|DMGL_AUTO
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DMGL_GNU
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DMGL_LUCID
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DMGL_ARM
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DMGL_HP
value|(1<< 12)
end_define

begin_comment
comment|/* For the HP aCC compiler;                                             same as ARM except for                                             template arguments, etc. */
end_comment

begin_define
define|#
directive|define
name|DMGL_EDG
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DMGL_GNU_V3
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DMGL_GNAT
value|(1<< 15)
end_define

begin_comment
comment|/* If none of these are set, use 'current_demangling_style' as the default. */
end_comment

begin_define
define|#
directive|define
name|DMGL_STYLE_MASK
value|(DMGL_AUTO|DMGL_GNU|DMGL_LUCID|DMGL_ARM|DMGL_HP|DMGL_EDG|DMGL_GNU_V3|DMGL_JAVA|DMGL_GNAT)
end_define

begin_comment
comment|/* Enumeration of possible demangling styles.     Lucid and ARM styles are still kept logically distinct, even though    they now both behave identically.  The resulting style is actual the    union of both.  I.E. either style recognizes both "__pt__" and "__rf__"    for operator "->", even though the first is lucid style and the second    is ARM style. (FIXME?) */
end_comment

begin_enum
specifier|extern
enum|enum
name|demangling_styles
block|{
name|unknown_demangling
init|=
literal|0
block|,
name|auto_demangling
init|=
name|DMGL_AUTO
block|,
name|gnu_demangling
init|=
name|DMGL_GNU
block|,
name|lucid_demangling
init|=
name|DMGL_LUCID
block|,
name|arm_demangling
init|=
name|DMGL_ARM
block|,
name|hp_demangling
init|=
name|DMGL_HP
block|,
name|edg_demangling
init|=
name|DMGL_EDG
block|,
name|gnu_v3_demangling
init|=
name|DMGL_GNU_V3
block|,
name|java_demangling
init|=
name|DMGL_JAVA
block|,
name|gnat_demangling
init|=
name|DMGL_GNAT
block|}
name|current_demangling_style
enum|;
end_enum

begin_comment
comment|/* Define string names for the various demangling styles. */
end_comment

begin_define
define|#
directive|define
name|AUTO_DEMANGLING_STYLE_STRING
value|"auto"
end_define

begin_define
define|#
directive|define
name|GNU_DEMANGLING_STYLE_STRING
value|"gnu"
end_define

begin_define
define|#
directive|define
name|LUCID_DEMANGLING_STYLE_STRING
value|"lucid"
end_define

begin_define
define|#
directive|define
name|ARM_DEMANGLING_STYLE_STRING
value|"arm"
end_define

begin_define
define|#
directive|define
name|HP_DEMANGLING_STYLE_STRING
value|"hp"
end_define

begin_define
define|#
directive|define
name|EDG_DEMANGLING_STYLE_STRING
value|"edg"
end_define

begin_define
define|#
directive|define
name|GNU_V3_DEMANGLING_STYLE_STRING
value|"gnu-v3"
end_define

begin_define
define|#
directive|define
name|JAVA_DEMANGLING_STYLE_STRING
value|"java"
end_define

begin_define
define|#
directive|define
name|GNAT_DEMANGLING_STYLE_STRING
value|"gnat"
end_define

begin_comment
comment|/* Some macros to test what demangling style is active. */
end_comment

begin_define
define|#
directive|define
name|CURRENT_DEMANGLING_STYLE
value|current_demangling_style
end_define

begin_define
define|#
directive|define
name|AUTO_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_AUTO)
end_define

begin_define
define|#
directive|define
name|GNU_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNU)
end_define

begin_define
define|#
directive|define
name|LUCID_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_LUCID)
end_define

begin_define
define|#
directive|define
name|ARM_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_ARM)
end_define

begin_define
define|#
directive|define
name|HP_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_HP)
end_define

begin_define
define|#
directive|define
name|EDG_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_EDG)
end_define

begin_define
define|#
directive|define
name|GNU_V3_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNU_V3)
end_define

begin_define
define|#
directive|define
name|JAVA_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_JAVA)
end_define

begin_define
define|#
directive|define
name|GNAT_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNAT)
end_define

begin_comment
comment|/* Provide information about the available demangle styles. This code is    pulled from gdb into libiberty because it is useful to binutils also.  */
end_comment

begin_struct
specifier|extern
struct|struct
name|demangler_engine
block|{
specifier|const
name|char
modifier|*
name|demangling_style_name
decl_stmt|;
name|enum
name|demangling_styles
name|demangling_style
decl_stmt|;
specifier|const
name|char
modifier|*
name|demangling_style_doc
decl_stmt|;
block|}
name|libiberty_demanglers
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cplus_demangle
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cplus_demangle_opname
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|opname
operator|,
name|char
operator|*
name|result
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cplus_mangle_opname
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|opname
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note: This sets global state.  FIXME if you care about multi-threading. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_cplus_marker_for_demangling
name|PARAMS
argument_list|(
operator|(
name|int
name|ch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|demangling_styles
name|cplus_demangle_set_style
name|PARAMS
argument_list|(
operator|(
expr|enum
name|demangling_styles
name|style
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|demangling_styles
name|cplus_demangle_name_to_style
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* V3 ABI demangling entry point, defined in cp-demangle.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cplus_demangle_v3
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEMANGLE_H */
end_comment

end_unit

