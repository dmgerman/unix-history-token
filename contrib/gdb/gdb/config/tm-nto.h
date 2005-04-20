begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine sub-description for QNX Neutrino version 6.    This is included by other tm-*.h files to specify nto specific    stuff.      Copyright 2003 Free Software Foundation, Inc.     This code was donated by QNX Software Systems Ltd.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TM_QNXNTO_H
end_ifndef

begin_define
define|#
directive|define
name|_TM_QNXNTO_H
end_define

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_comment
comment|/* Setup the valid realtime signal range.  */
end_comment

begin_define
define|#
directive|define
name|REALTIME_LO
value|41
end_define

begin_define
define|#
directive|define
name|REALTIME_HI
value|56
end_define

begin_comment
comment|/* Set up the undefined useable signals.  */
end_comment

begin_define
define|#
directive|define
name|RAW_SIGNAL_LO
value|32
end_define

begin_define
define|#
directive|define
name|RAW_SIGNAL_HI
value|(REALTIME_LO - 1)
end_define

begin_define
define|#
directive|define
name|TARGET_SIGNAL_RAW_VALUES
define|\
value|TARGET_SIGNAL_RAW0, \ TARGET_SIGNAL_RAW1, \ TARGET_SIGNAL_RAW2, \ TARGET_SIGNAL_RAW3, \ TARGET_SIGNAL_RAW4, \ TARGET_SIGNAL_RAW5, \ TARGET_SIGNAL_RAW6, \ TARGET_SIGNAL_RAW7, \ TARGET_SIGNAL_RAW8
end_define

begin_define
define|#
directive|define
name|TARGET_SIGNAL_RAW_TABLE
define|\
value|{"SIGNAL32", "Signal 32"}, \ {"SIGNAL33", "Signal 33"}, \ {"SIGNAL34", "Signal 34"}, \ {"SIGNAL35", "Signal 35"}, \ {"SIGNAL36", "Signal 36"}, \ {"SIGNAL37", "Signal 37"}, \ {"SIGNAL38", "Signal 38"}, \ {"SIGNAL39", "Signal 39"}, \ {"SIGNAL40", "Signal 40"}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TM_QNXNTO_H */
end_comment

end_unit

