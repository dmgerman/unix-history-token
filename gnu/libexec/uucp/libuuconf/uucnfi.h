begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uucnfi.h    Internal header file for the uuconf package.     Copyright (C) 1992, 1993, 1994, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* This is the internal header file for the uuconf package.  It should    not be included by anything other than the uuconf code itself.  */
end_comment

begin_comment
comment|/* Get all the general definitions.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_comment
comment|/* Get the uuconf header file itself.  */
end_comment

begin_include
include|#
directive|include
file|"uuconf.h"
end_include

begin_comment
comment|/* We need the system dependent header file.  */
end_comment

begin_include
include|#
directive|include
file|"syshdr.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* This is the generic information structure.  This holds all the    per-thread global information needed by the uuconf code.  The    per-process global information is held in an sprocess structure,    which this structure points to.  This permits the code to not have    any global variables at all.  */
end_comment

begin_struct
struct|struct
name|sglobal
block|{
comment|/* A pointer to the per-process global information.  */
name|struct
name|sprocess
modifier|*
name|qprocess
decl_stmt|;
comment|/* A memory block in which all the memory for these fields is      allocated.  */
name|pointer
name|pblock
decl_stmt|;
comment|/* The value of errno after an error.  */
name|int
name|ierrno
decl_stmt|;
comment|/* The filename for which an error occurred.  */
specifier|const
name|char
modifier|*
name|zfilename
decl_stmt|;
comment|/* The line number at which an error occurred.  */
name|int
name|ilineno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the per-process information structure.  This essentially    holds all the global variables used by uuconf.  */
end_comment

begin_struct
struct|struct
name|sprocess
block|{
comment|/* The name of the local machine.  This will be NULL if it is not      specified in a configuration file.  */
specifier|const
name|char
modifier|*
name|zlocalname
decl_stmt|;
comment|/* The spool directory.  */
specifier|const
name|char
modifier|*
name|zspooldir
decl_stmt|;
comment|/* The default public directory.  */
specifier|const
name|char
modifier|*
name|zpubdir
decl_stmt|;
comment|/* The lock directory.  */
specifier|const
name|char
modifier|*
name|zlockdir
decl_stmt|;
comment|/* The log file.  */
specifier|const
name|char
modifier|*
name|zlogfile
decl_stmt|;
comment|/* The statistics file.  */
specifier|const
name|char
modifier|*
name|zstatsfile
decl_stmt|;
comment|/* The debugging file.  */
specifier|const
name|char
modifier|*
name|zdebugfile
decl_stmt|;
comment|/* The default debugging level.  */
specifier|const
name|char
modifier|*
name|zdebug
decl_stmt|;
comment|/* Whether login information should be stripped.  */
name|boolean
name|fstrip_login
decl_stmt|;
comment|/* Whether protocol information should be stripped.  */
name|boolean
name|fstrip_proto
decl_stmt|;
comment|/* The maximum number of simultaneously executing uuxqts.  */
name|int
name|cmaxuuxqts
decl_stmt|;
comment|/* How often to spawn a uuxqt process.  */
specifier|const
name|char
modifier|*
name|zrunuuxqt
decl_stmt|;
comment|/* Whether we are reading the V2 configuration files.  */
name|boolean
name|fv2
decl_stmt|;
comment|/* Whether we are reading the HDB configuration files.  */
name|boolean
name|fhdb
decl_stmt|;
comment|/* The names of the dialcode files.  */
name|char
modifier|*
modifier|*
name|pzdialcodefiles
decl_stmt|;
comment|/* Timetables.  These are in pairs.  The first element is the name,      the second is the time string.  */
name|char
modifier|*
modifier|*
name|pztimetables
decl_stmt|;
comment|/* Taylor UUCP config file name.  */
name|char
modifier|*
name|zconfigfile
decl_stmt|;
comment|/* Taylor UUCP sys file names.  */
name|char
modifier|*
modifier|*
name|pzsysfiles
decl_stmt|;
comment|/* Taylor UUCP port file names.  */
name|char
modifier|*
modifier|*
name|pzportfiles
decl_stmt|;
comment|/* Taylor UUCP dial file names.  */
name|char
modifier|*
modifier|*
name|pzdialfiles
decl_stmt|;
comment|/* Taylor UUCP passwd file names.  */
name|char
modifier|*
modifier|*
name|pzpwdfiles
decl_stmt|;
comment|/* Taylor UUCP call file names.  */
name|char
modifier|*
modifier|*
name|pzcallfiles
decl_stmt|;
comment|/* List of "unknown" commands from config file.  */
name|struct
name|sunknown
modifier|*
name|qunknown
decl_stmt|;
comment|/* Whether the Taylor UUCP system information locations have been      read.  */
name|boolean
name|fread_syslocs
decl_stmt|;
comment|/* Taylor UUCP system information locations.  */
name|struct
name|stsysloc
modifier|*
name|qsyslocs
decl_stmt|;
comment|/* Taylor UUCP validation restrictions.  */
name|struct
name|svalidate
modifier|*
name|qvalidate
decl_stmt|;
comment|/* Whether the "myname" command is used in a Taylor UUCP file.  */
name|boolean
name|fuses_myname
decl_stmt|;
comment|/* V2 system file name (L.sys).  */
name|char
modifier|*
name|zv2systems
decl_stmt|;
comment|/* V2 device file name (L-devices).  */
name|char
modifier|*
name|zv2devices
decl_stmt|;
comment|/* V2 user permissions file name (USERFILE).  */
name|char
modifier|*
name|zv2userfile
decl_stmt|;
comment|/* V2 user permitted commands file (L.cmds).  */
name|char
modifier|*
name|zv2cmds
decl_stmt|;
comment|/* HDB system file names (Systems).  */
name|char
modifier|*
modifier|*
name|pzhdb_systems
decl_stmt|;
comment|/* HDB device file names (Devices).  */
name|char
modifier|*
modifier|*
name|pzhdb_devices
decl_stmt|;
comment|/* HDB dialer file names (Dialers).  */
name|char
modifier|*
modifier|*
name|pzhdb_dialers
decl_stmt|;
comment|/* Whether the HDB Permissions file has been read.  */
name|boolean
name|fhdb_read_permissions
decl_stmt|;
comment|/* The HDB Permissions file entries.  */
name|struct
name|shpermissions
modifier|*
name|qhdb_permissions
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* This structure is used to hold the "unknown" commands from the    Taylor UUCP config file before they have been parsed.  */
end_comment

begin_struct
struct|struct
name|sunknown
block|{
comment|/* Next element in linked list.  */
name|struct
name|sunknown
modifier|*
name|qnext
decl_stmt|;
comment|/* Line number in config file.  */
name|int
name|ilineno
decl_stmt|;
comment|/* Number of arguments.  */
name|int
name|cargs
decl_stmt|;
comment|/* Arguments.  */
name|char
modifier|*
modifier|*
name|pzargs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used to hold the locations of systems within the    Taylor UUCP sys files.  */
end_comment

begin_struct
struct|struct
name|stsysloc
block|{
comment|/* Next element in linked list.  */
name|struct
name|stsysloc
modifier|*
name|qnext
decl_stmt|;
comment|/* System name.  */
specifier|const
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* Whether system is an alias or a real system.  If this is an      alias, the real system is the next entry in the linked list which      is not an alias.  */
name|boolean
name|falias
decl_stmt|;
comment|/* File name (one of the sys files).  */
specifier|const
name|char
modifier|*
name|zfile
decl_stmt|;
comment|/* Open file.  */
name|FILE
modifier|*
name|e
decl_stmt|;
comment|/* Location within file (from ftell).  */
name|long
name|iloc
decl_stmt|;
comment|/* Line number within file.  */
name|int
name|ilineno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used to hold validation restrictions.  This is a    list of machines which are permitted to use a particular login    name.  If a machine logs in, and there is no called login entry for    it, the login name and machine name must be passed to    uuconf_validate to confirm that either there is no entry for this    login name or that the machine name appears on the entry.  */
end_comment

begin_struct
struct|struct
name|svalidate
block|{
comment|/* Next element in linked list.  */
name|struct
name|svalidate
modifier|*
name|qnext
decl_stmt|;
comment|/* Login name.  */
specifier|const
name|char
modifier|*
name|zlogname
decl_stmt|;
comment|/* NULL terminated list of machine names.  */
name|char
modifier|*
modifier|*
name|pzmachines
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* This structure is used to hold a linked list of HDB Permissions    file entries.  */
end_comment

begin_struct
struct|struct
name|shpermissions
block|{
comment|/* Next entry in linked list.  */
name|struct
name|shpermissions
modifier|*
name|qnext
decl_stmt|;
comment|/* NULL terminated array of LOGNAME values.   */
name|char
modifier|*
modifier|*
name|pzlogname
decl_stmt|;
comment|/* NULL terminated array of MACHINE values.  */
name|char
modifier|*
modifier|*
name|pzmachine
decl_stmt|;
comment|/* Boolean REQUEST value.  */
name|int
name|frequest
decl_stmt|;
comment|/* Boolean SENDFILES value ("call" is taken as "no").  */
name|int
name|fsendfiles
decl_stmt|;
comment|/* NULL terminated array of READ values.  */
name|char
modifier|*
modifier|*
name|pzread
decl_stmt|;
comment|/* NULL terminated array of WRITE values.  */
name|char
modifier|*
modifier|*
name|pzwrite
decl_stmt|;
comment|/* Boolean CALLBACK value.  */
name|int
name|fcallback
decl_stmt|;
comment|/* NULL terminated array of COMMANDS values.  */
name|char
modifier|*
modifier|*
name|pzcommands
decl_stmt|;
comment|/* NULL terminated array of VALIDATE values.  */
name|char
modifier|*
modifier|*
name|pzvalidate
decl_stmt|;
comment|/* String MYNAME value.  */
name|char
modifier|*
name|zmyname
decl_stmt|;
comment|/* String PUBDIR value.  */
specifier|const
name|char
modifier|*
name|zpubdir
decl_stmt|;
comment|/* NULL terminated array of ALIAS values.  */
name|char
modifier|*
modifier|*
name|pzalias
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* This structure is used to build reentrant uuconf_cmdtab tables.    The ioff field is either (size_t) -1 or an offsetof macro.  The    table is then copied into a uuconf_cmdtab, except that offsets of    (size_t) -1 are converted to pvar elements of NULL, and other    offsets are converted to an offset off some base address.  */
end_comment

begin_struct
struct|struct
name|cmdtab_offset
block|{
specifier|const
name|char
modifier|*
name|zcmd
decl_stmt|;
name|int
name|itype
decl_stmt|;
name|size_t
name|ioff
decl_stmt|;
name|uuconf_cmdtabfn
name|pifn
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* A value in a uuconf_system structure which holds the address of    this special variable is known to be uninitialized.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_uuconf_unset
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Internal function to read a system from the Taylor UUCP    configuration files.  This does not apply the basic defaults.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_itaylor_system_internal
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read the system locations and validation information from the    Taylor UUCP configuration files.  This sets the qsyslocs,    qvalidate, and fread_syslocs elements of the global structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iread_locations
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a command for a port from a Taylor UUCP file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iport_cmd
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
expr|struct
name|uuconf_port
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a command for a dialer from a Taylor UUCP file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_idialer_cmd
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a command for a chat script from a Taylor UUCP file; this    is also called for HDB or V2 files, with a made up command.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_ichat_cmd
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
expr|struct
name|uuconf_chat
operator|*
name|qchat
operator|,
name|pointer
name|pblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a protocol-parameter command from a Taylor UUCP file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iadd_proto_param
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
expr|struct
name|uuconf_proto_param
operator|*
operator|*
name|pq
operator|,
name|pointer
name|pblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle a "seven-bit", "reliable", or "half-duplex" command from a    Taylor UUCP port or dialer file.  The pvar field should point to    the ireliable element of the structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iseven_bit
name|P
argument_list|(
operator|(
name|pointer
name|pglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|pointer
name|pvar
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_ireliable
name|P
argument_list|(
operator|(
name|pointer
name|pglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|pointer
name|pvar
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_ihalf_duplex
name|P
argument_list|(
operator|(
name|pointer
name|pglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|pointer
name|pvar
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal function to read a system from the V2 configuration files.    This does not apply the basic defaults.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iv2_system_internal
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal function to read a system from the HDB configuration    files.  This does not apply the basic defaults.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_ihdb_system_internal
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read the HDB Permissions file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_ihread_permissions
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the global information structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iinit_global
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
operator|*
name|pqglobal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear system information.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_uuconf_uclear_system
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default unset aspects of one system to the contents of another.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_isystem_default
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
expr|struct
name|uuconf_system
operator|*
name|q
operator|,
expr|struct
name|uuconf_system
operator|*
name|qdefault
operator|,
name|boolean
name|faddalternates
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Put in the basic system defaults.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_isystem_basic_default
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear port information.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_uuconf_uclear_port
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_port
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear dialer information.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_uuconf_uclear_dialer
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_dialer
operator|*
name|qdialer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a timetable.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_itimetable
name|P
argument_list|(
operator|(
name|pointer
name|pglobal
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|pointer
name|pvar
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a time string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_itime_parse
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|char
operator|*
name|ztime
operator|,
name|long
name|ival
operator|,
name|int
name|cretry
operator|,
name|int
argument_list|(
argument|*picmp
argument_list|)
name|P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
operator|,
expr|struct
name|uuconf_timespan
operator|*
operator|*
name|pqspan
operator|,
name|pointer
name|pblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A grade comparison function to pass to _uuconf_itime_parse.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_itime_grade_cmp
name|P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a debugging string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_idebug_cmd
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|char
operator|*
operator|*
name|pzdebug
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|pointer
name|pblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a string to a NULL terminated list of strings.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iadd_string
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|char
operator|*
name|zadd
operator|,
name|boolean
name|fcopy
operator|,
name|boolean
name|fdupcheck
operator|,
name|char
operator|*
operator|*
operator|*
name|ppzstrings
operator|,
name|pointer
name|pblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a string into a boolean value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iboolean
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
specifier|const
name|char
operator|*
name|zval
operator|,
name|int
operator|*
name|pi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a string into an integer value.  The argument p is either an    int * or a long *, according to the argument fint.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_iint
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
specifier|const
name|char
operator|*
name|zval
operator|,
name|pointer
name|p
operator|,
name|boolean
name|fint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn a cmdtab_offset table into a uuconf_cmdtab table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_uuconf_ucmdtab_base
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmdtab_offset
operator|*
name|qoff
operator|,
name|size_t
name|celes
operator|,
name|char
operator|*
name|pbase
operator|,
expr|struct
name|uuconf_cmdtab
operator|*
name|qset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Merge two memory blocks into one.  This cannot fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|_uuconf_pmalloc_block_merge
name|P
argument_list|(
operator|(
name|pointer
operator|,
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A wrapper for getline that continues lines if they end in a    backslash.  It needs qglobal so that it can increment ilineno    correctly.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_getline
name|P
argument_list|(
operator|(
expr|struct
name|sglobal
operator|*
name|qglobal
operator|,
name|char
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Split a string into tokens.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_uuconf_istrsplit
name|P
argument_list|(
operator|(
name|char
operator|*
name|zline
operator|,
name|int
name|bsep
operator|,
name|char
operator|*
operator|*
operator|*
name|ppzsplit
operator|,
name|size_t
operator|*
name|csplit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

