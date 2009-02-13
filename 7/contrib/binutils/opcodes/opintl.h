begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opintl.h - opcodes specific header for gettext code.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     Written by Tom Tromey<tromey@cygnus.com>     This file is part of the opcodes library used by GAS and the GNU binutils.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_comment
comment|/* Note the use of dgetext() and PACKAGE here, rather than gettext().        This is because the code in this directory is used to build a library which    will be linked with code in other directories to form programs.  We want to    maintain a seperate translation file for this directory however, rather    than being forced to merge it with that of any program linked to    libopcodes.  This is a library, so it cannot depend on the catalog    currently loaded.     In order to do this, we have to make sure that when we extract messages we    use the OPCODES domain rather than the domain of the program that included    the opcodes library, (eg OBJDUMP).  Hence we use dgettext (PACKAGE, String)    and define PACKAGE to be 'opcodes'.  (See the code in configure).  */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|dgettext (PACKAGE, String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gettext_noop
end_ifdef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|gettext_noop (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

