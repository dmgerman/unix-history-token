begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opintl.h - opcodes specific header for gettext code.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.     Written by Tom Tromey<tromey@cygnus.com>     This file is part of the opcodes library used by GAS and the GNU binutils.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA. */
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

begin_comment
comment|/* Stubs that do something close enough.  */
end_comment

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domain
parameter_list|,
name|Message
parameter_list|)
value|(Message)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domain
parameter_list|,
name|Message
parameter_list|,
name|Type
parameter_list|)
value|(Message)
end_define

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domain
parameter_list|,
name|Directory
parameter_list|)
value|(Domain)
end_define

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

