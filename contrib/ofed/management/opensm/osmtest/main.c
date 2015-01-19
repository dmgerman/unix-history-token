begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Command line interface for osmtest.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_debug.h>
end_include

begin_include
include|#
directive|include
file|"osmtest.h"
end_include

begin_comment
comment|/********************************************************************        D E F I N E    G L O B A L    V A R I A B L E S *********************************************************************/
end_comment

begin_comment
comment|/* 	This is the global osmtest object. 	One osmtest object is required per subnet. 	Future versions could support multiple subents by 	instantiating more than one osmtest object. */
end_comment

begin_define
define|#
directive|define
name|GUID_ARRAY_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|OSMT_DEFAULT_RETRY_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|OSMT_DEFAULT_TRANS_TIMEOUT_MILLISEC
value|1000
end_define

begin_define
define|#
directive|define
name|OSMT_DEFAULT_TRAP_WAIT_TIMEOUT_SEC
value|10
end_define

begin_define
define|#
directive|define
name|INVALID_GUID
value|(0xFFFFFFFFFFFFFFFFULL)
end_define

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function
name|boolean_t
name|osmt_is_debug
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_
argument_list|)
return|return
name|TRUE
return|;
else|#
directive|else
return|return
name|FALSE
return|;
endif|#
directive|endif
comment|/* defined( _DEBUG_ ) */
block|}
end_function

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function_decl
name|void
name|show_usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|show_usage
parameter_list|()
block|{
name|printf
argument_list|(
literal|"\n------- osmtest - Usage and options ----------------------\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Usage:	  osmtest [options]\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Options:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-f<c|a|v|s|e|f|m|q|t>\n"
literal|"--flow<c|a|v|s|e|f|m|q|t>\n"
literal|"          This option directs osmtest to run a specific flow:\n"
literal|"          FLOW  DESCRIPTION\n"
literal|"          c = create an inventory file with all nodes, ports and paths\n"
literal|"          a = run all validation tests (expecting an input inventory)\n"
literal|"          v = only validate the given inventory file\n"
literal|"          s = run service registration, deregistration, and lease test\n"
literal|"          e = run event forwarding test\n"
literal|"          f = flood the SA with queries according to the stress mode\n"
literal|"          m = multicast flow\n"
literal|"          q = QoS info: dump VLArb and SLtoVL tables\n"
literal|"          t = run trap 64/65 flow (this flow requires running of external tool)\n"
literal|"          (default is all flows except QoS)\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-w<trap_wait_time>\n"
literal|"--wait<trap_wait_time>\n"
literal|"          This option specifies the wait time for trap 64/65 in seconds\n"
literal|"          It is used only when running -f t - the trap 64/65 flow\n"
literal|"          (default to 10 sec)\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-d<number>\n"
literal|"--debug<number>\n"
literal|"          This option specifies a debug option\n"
literal|"          These options are not normally needed\n"
literal|"          The number following -d selects the debug\n"
literal|"          option to enable as follows:\n"
literal|"          OPT   Description\n"
literal|"          ---    -----------------\n"
literal|"          -d0  - Unused.\n"
literal|"          -d1  - Do not scan/compare path records.\n"
literal|"          -d2  - Force log flushing after each log message.\n"
literal|"          Without -d, no debug options are enabled\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-m<LID in hex>\n"
literal|"--max_lid<LID in hex>\n"
literal|"          This option specifies the maximal LID number to be searched\n"
literal|"          for during inventory file build (default to 100)\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-g<GUID in hex>\n"
literal|"--guid<GUID in hex>\n"
literal|"          This option specifies the local port GUID value\n"
literal|"          with which osmtest should bind.  osmtest may be\n"
literal|"          bound to 1 port at a time\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-p \n"
literal|"--port\n"
literal|"          This option displays a menu of possible local port GUID values\n"
literal|"          with which osmtest could bind\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-h\n"
literal|"--help\n"
literal|"          Display this usage info then exit\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-i<filename>\n"
literal|"--inventory<filename>\n"
literal|"          This option specifies the name of the inventory file\n"
literal|"          Normally, osmtest expects to find an inventory file,\n"
literal|"          which osmtest uses to validate real-time information\n"
literal|"          received from the SA during testing\n"
literal|"          If -i is not specified, osmtest defaults to the file\n"
literal|"          'osmtest.dat'\n"
literal|"          See -c option for related information\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-s\n"
literal|"--stress\n"
literal|"          This option runs the specified stress test instead\n"
literal|"          of the normal test suite\n"
literal|"          Stress test options are as follows:\n"
literal|"          OPT    Description\n"
literal|"          ---    -----------------\n"
literal|"          -s1  - Single-MAD response SA queries\n"
literal|"          -s2  - Multi-MAD (RMPP) response SA queries\n"
literal|"          -s3  - Multi-MAD (RMPP) Path Record SA queries\n"
literal|"          Without -s, stress testing is not performed\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-M\n"
literal|"--Multicast_Mode\n"
literal|"          This option specify length of Multicast test:\n"
literal|"          OPT    Description\n"
literal|"          ---    -----------------\n"
literal|"          -M1  - Short Multicast Flow (default) - single mode\n"
literal|"          -M2  - Short Multicast Flow - multiple mode\n"
literal|"          -M3  - Long Multicast Flow - single mode\n"
literal|"          -M4  - Long Multicast Flow - multiple mode\n"
literal|" Single mode - Osmtest is tested alone, with no other\n"
literal|"   apps that interact with OpenSM MC\n"
literal|" Multiple mode - Could be run with other apps using MC with\n"
literal|"   OpenSM."
literal|" Without -M, default flow testing is performed\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-t<milliseconds>\n"
literal|"          This option specifies the time in milliseconds\n"
literal|"          used for transaction timeouts\n"
literal|"          Specifying -t 0 disables timeouts\n"
literal|"          Without -t, osmtest defaults to a timeout value of\n"
literal|"          1 second\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-l\n"
literal|"--log_file\n"
literal|"          This option defines the log to be the given file\n"
literal|"          By default the log goes to stdout\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-v\n"
literal|"          This option increases the log verbosity level\n"
literal|"          The -v option may be specified multiple times\n"
literal|"          to further increase the verbosity level\n"
literal|"          See the -vf option for more information about.\n"
literal|"          log verbosity\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-V\n"
literal|"          This option sets the maximum verbosity level and\n"
literal|"          forces log flushing\n"
literal|"          The -V is equivalent to '-vf 0xFF -d 2'\n"
literal|"          See the -vf option for more information about.\n"
literal|"          log verbosity\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-vf<flags>\n"
literal|"          This option sets the log verbosity level\n"
literal|"          A flags field must follow the -vf option\n"
literal|"          A bit set/clear in the flags enables/disables a\n"
literal|"          specific log level as follows:\n"
literal|"          BIT    LOG LEVEL ENABLED\n"
literal|"          ----   -----------------\n"
literal|"          0x01 - ERROR (error messages)\n"
literal|"          0x02 - INFO (basic messages, low volume)\n"
literal|"          0x04 - VERBOSE (interesting stuff, moderate volume)\n"
literal|"          0x08 - DEBUG (diagnostic, high volume)\n"
literal|"          0x10 - FUNCS (function entry/exit, very high volume)\n"
literal|"          0x20 - FRAMES (dumps all SMP and GMP frames)\n"
literal|"          0x40 - currently unused\n"
literal|"          0x80 - currently unused\n"
literal|"          Without -vf, osmtest defaults to ERROR + INFO (0x3)\n"
literal|"          Specifying -vf 0 disables all messages\n"
literal|"          Specifying -vf 0xFF enables all messages (see -V)\n"
literal|"          High verbosity levels may require increasing\n"
literal|"          the transaction timeout with the -t option\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function_decl
specifier|static
name|void
name|print_all_guids
parameter_list|(
name|IN
name|osmtest_t
modifier|*
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|print_all_guids
parameter_list|(
name|IN
name|osmtest_t
modifier|*
name|p_osmt
parameter_list|)
block|{
name|ib_api_status_t
name|status
decl_stmt|;
name|uint32_t
name|num_ports
init|=
name|GUID_ARRAY_SIZE
decl_stmt|;
name|ib_port_attr_t
name|attr_array
index|[
name|GUID_ARRAY_SIZE
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	   Call the transport layer for a list of local port 	   GUID values. 	 */
name|status
operator|=
name|osm_vendor_get_all_port_attr
argument_list|(
name|p_osmt
operator|->
name|p_vendor
argument_list|,
name|attr_array
argument_list|,
operator|&
name|num_ports
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|IB_SUCCESS
condition|)
block|{
name|printf
argument_list|(
literal|"\nError from osm_vendor_get_all_port_attr (%x)\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
name|printf
argument_list|(
literal|"\nListing GUIDs:\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_ports
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"Port %i: 0x%"
name|PRIx64
literal|"\n"
argument_list|,
name|i
argument_list|,
name|cl_hton64
argument_list|(
name|attr_array
index|[
name|i
index|]
operator|.
name|port_guid
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function
name|ib_net64_t
name|get_port_guid
parameter_list|(
name|IN
name|osmtest_t
modifier|*
name|p_osmt
parameter_list|,
name|uint64_t
name|port_guid
parameter_list|)
block|{
name|ib_api_status_t
name|status
decl_stmt|;
name|uint32_t
name|num_ports
init|=
name|GUID_ARRAY_SIZE
decl_stmt|;
name|ib_port_attr_t
name|attr_array
index|[
name|GUID_ARRAY_SIZE
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	   Call the transport layer for a list of local port 	   GUID values. 	 */
comment|/* "local ports" is(?) phys, shouldn't this exclude port 0 then ? */
name|status
operator|=
name|osm_vendor_get_all_port_attr
argument_list|(
name|p_osmt
operator|->
name|p_vendor
argument_list|,
name|attr_array
argument_list|,
operator|&
name|num_ports
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|IB_SUCCESS
condition|)
block|{
name|printf
argument_list|(
literal|"\nError from osm_vendor_get_all_port_attr (%x)\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|num_ports
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"using default guid 0x%"
name|PRIx64
literal|"\n"
argument_list|,
name|cl_hton64
argument_list|(
name|attr_array
index|[
literal|0
index|]
operator|.
name|port_guid
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|attr_array
index|[
literal|0
index|]
operator|.
name|port_guid
operator|)
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_ports
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|attr_array
index|[
name|i
index|]
operator|.
name|port_guid
operator|==
name|port_guid
operator|||
operator|(
operator|!
name|port_guid
operator|&&
name|attr_array
index|[
name|i
index|]
operator|.
name|link_state
operator|>
name|IB_LINK_DOWN
operator|)
condition|)
return|return
name|attr_array
index|[
name|i
index|]
operator|.
name|port_guid
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**********************************************************************  **********************************************************************/
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
specifier|static
name|osmtest_t
name|osm_test
decl_stmt|;
name|osmtest_opt_t
name|opt
init|=
block|{
literal|0
block|}
decl_stmt|;
name|ib_net64_t
name|guid
init|=
literal|0
decl_stmt|;
name|uint16_t
name|max_lid
init|=
literal|100
decl_stmt|;
name|ib_api_status_t
name|status
decl_stmt|;
name|uint32_t
name|log_flags
init|=
name|OSM_LOG_ERROR
operator||
name|OSM_LOG_INFO
decl_stmt|;
name|int32_t
name|vendor_debug
init|=
literal|0
decl_stmt|;
name|char
name|flow_name
index|[
literal|64
index|]
decl_stmt|;
name|uint32_t
name|next_option
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|short_option
init|=
literal|"f:l:m:M:d:g:s:t:i:pcvVh"
decl_stmt|;
comment|/* 	 * In the array below, the 2nd parameter specified the number 	 * of arguments as follows: 	 * 0: no arguments 	 * 1: argument 	 * 2: optional 	 */
specifier|const
name|struct
name|option
name|long_option
index|[]
init|=
block|{
block|{
literal|"create"
block|,
literal|0
block|,
name|NULL
block|,
literal|'c'
block|}
block|,
block|{
literal|"debug"
block|,
literal|1
block|,
name|NULL
block|,
literal|'d'
block|}
block|,
block|{
literal|"flow"
block|,
literal|1
block|,
name|NULL
block|,
literal|'f'
block|}
block|,
block|{
literal|"wait"
block|,
literal|1
block|,
name|NULL
block|,
literal|'w'
block|}
block|,
block|{
literal|"inventory"
block|,
literal|1
block|,
name|NULL
block|,
literal|'i'
block|}
block|,
block|{
literal|"max_lid"
block|,
literal|1
block|,
name|NULL
block|,
literal|'m'
block|}
block|,
block|{
literal|"guid"
block|,
literal|2
block|,
name|NULL
block|,
literal|'g'
block|}
block|,
block|{
literal|"port"
block|,
literal|0
block|,
name|NULL
block|,
literal|'p'
block|}
block|,
block|{
literal|"help"
block|,
literal|0
block|,
name|NULL
block|,
literal|'h'
block|}
block|,
block|{
literal|"stress"
block|,
literal|1
block|,
name|NULL
block|,
literal|'s'
block|}
block|,
block|{
literal|"Multicast_Mode"
block|,
literal|1
block|,
name|NULL
block|,
literal|'M'
block|}
block|,
block|{
literal|"timeout"
block|,
literal|1
block|,
name|NULL
block|,
literal|'t'
block|}
block|,
block|{
literal|"verbose"
block|,
literal|0
block|,
name|NULL
block|,
literal|'v'
block|}
block|,
block|{
literal|"log_file"
block|,
literal|1
block|,
name|NULL
block|,
literal|'l'
block|}
block|,
block|{
literal|"vf"
block|,
literal|1
block|,
name|NULL
block|,
literal|'x'
block|}
block|,
block|{
literal|"V"
block|,
literal|0
block|,
name|NULL
block|,
literal|'V'
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|,
name|NULL
block|,
literal|0
block|}
comment|/* Required at end of array */
block|}
decl_stmt|;
comment|/* Make sure that the opensm, complib and osmtest were compiled using 	   same modes (debug/free) */
if|if
condition|(
name|osm_is_debug
argument_list|()
operator|!=
name|cl_is_debug
argument_list|()
operator|||
name|osm_is_debug
argument_list|()
operator|!=
name|osmt_is_debug
argument_list|()
operator|||
name|osmt_is_debug
argument_list|()
operator|!=
name|cl_is_debug
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-E- OpenSM, Complib and OsmTest were compiled using different modes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-E- OpenSM debug:%d Complib debug:%d OsmTest debug:%d \n"
argument_list|,
name|osm_is_debug
argument_list|()
argument_list|,
name|cl_is_debug
argument_list|()
argument_list|,
name|osmt_is_debug
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|opt
operator|.
name|transaction_timeout
operator|=
name|OSMT_DEFAULT_TRANS_TIMEOUT_MILLISEC
expr_stmt|;
name|opt
operator|.
name|wait_time
operator|=
name|OSMT_DEFAULT_TRAP_WAIT_TIMEOUT_SEC
expr_stmt|;
name|opt
operator|.
name|retry_count
operator|=
name|OSMT_DEFAULT_RETRY_COUNT
expr_stmt|;
name|opt
operator|.
name|force_log_flush
operator|=
name|FALSE
expr_stmt|;
name|opt
operator|.
name|stress
operator|=
literal|0
expr_stmt|;
name|opt
operator|.
name|log_file
operator|=
name|NULL
expr_stmt|;
name|opt
operator|.
name|create
operator|=
name|FALSE
expr_stmt|;
name|opt
operator|.
name|mmode
operator|=
literal|1
expr_stmt|;
name|opt
operator|.
name|ignore_path_records
operator|=
name|FALSE
expr_stmt|;
comment|/*  Do path Records too */
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_ALL
expr_stmt|;
comment|/*  run all validation tests */
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"All Validations"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|opt
operator|.
name|file_name
argument_list|,
literal|"osmtest.dat"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nCommand Line Arguments\n"
argument_list|)
expr_stmt|;
do|do
block|{
name|next_option
operator|=
name|getopt_long_only
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|short_option
argument_list|,
name|long_option
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|next_option
condition|)
block|{
case|case
literal|'c'
case|:
comment|/* 			 * Create the inventory file. 			 */
name|opt
operator|.
name|create
operator|=
name|TRUE
expr_stmt|;
name|printf
argument_list|(
literal|"\tCreating inventory file\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* 			 * Specifies inventory file name. 			 */
if|if
condition|(
name|strlen
argument_list|(
name|optarg
argument_list|)
operator|>
name|OSMTEST_FILE_PATH_MAX
condition|)
name|printf
argument_list|(
literal|"\nError: path name too long (ignored)\n"
argument_list|)
expr_stmt|;
else|else
name|strcpy
argument_list|(
name|opt
operator|.
name|file_name
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tFile = %s\n"
argument_list|,
name|opt
operator|.
name|file_name
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* 			 * Specifies Flow . 			 */
if|if
condition|(
name|strlen
argument_list|(
name|optarg
argument_list|)
operator|>
name|OSMTEST_FILE_PATH_MAX
condition|)
name|printf
argument_list|(
literal|"\nError: path name too long (ignored)\n"
argument_list|)
expr_stmt|;
else|else
name|strcpy
argument_list|(
name|flow_name
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"c"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Create Inventory"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_CREATE_INVENTORY
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"v"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Validate Inventory"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_VALIDATE_INVENTORY
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"s"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Services Registration"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_SERVICE_REGISTRATION
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"e"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Event Forwarding"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_EVENT_FORWARDING
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"f"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Stress SA"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_STRESS_SA
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"m"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Multicast"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_MULTICAST
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"q"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"QoS: VLArb and SLtoVL"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_QOS
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"t"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"Trap 64/65"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_TRAP
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
literal|"a"
argument_list|,
name|optarg
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|flow_name
argument_list|,
literal|"All Validations"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|flow
operator|=
name|OSMT_FLOW_ALL
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\nError: unknown flow %s\n"
argument_list|,
name|flow_name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'w'
case|:
comment|/* 			 * Specifies trap 64/65 wait time 			 */
name|CL_ASSERT
argument_list|(
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0x100
argument_list|)
expr_stmt|;
name|opt
operator|.
name|wait_time
operator|=
operator|(
name|uint8_t
operator|)
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTrap 64/65 wait time = %d\n"
argument_list|,
name|opt
operator|.
name|wait_time
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* 			 * Specifies the max LID to search for during exploration. 			 */
name|max_lid
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tMAX-LID %u\n"
argument_list|,
name|max_lid
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
comment|/* 			 * Specifies port guid with which to bind. 			 */
name|guid
operator|=
name|cl_hton64
argument_list|(
name|strtoull
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Guid<0x%"
name|PRIx64
literal|">\n"
argument_list|,
name|cl_hton64
argument_list|(
name|guid
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
comment|/* 			 * Display current port guids 			 */
name|guid
operator|=
name|INVALID_GUID
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* 			 * Specifies transaction timeout. 			 */
name|opt
operator|.
name|transaction_timeout
operator|=
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tTransaction timeout = %d\n"
argument_list|,
name|opt
operator|.
name|transaction_timeout
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|opt
operator|.
name|log_file
operator|=
name|optarg
expr_stmt|;
name|printf
argument_list|(
literal|"\tLog File:%s\n"
argument_list|,
name|opt
operator|.
name|log_file
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
comment|/* 			 * Increases log verbosity. 			 */
name|log_flags
operator|=
operator|(
name|log_flags
operator|<<
literal|1
operator|)
operator||
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"\tVerbose option -v (log flags = 0x%X)\n"
argument_list|,
name|log_flags
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
comment|/* 			 * Specifies maximum log verbosity. 			 */
name|log_flags
operator|=
literal|0xFFFFFFFF
expr_stmt|;
name|opt
operator|.
name|force_log_flush
operator|=
name|TRUE
expr_stmt|;
name|printf
argument_list|(
literal|"\tEnabling maximum log verbosity\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* 			 * Perform stress test. 			 */
name|opt
operator|.
name|stress
operator|=
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tStress test enabled: "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|opt
operator|.
name|stress
condition|)
block|{
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"Small SA queries\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"Large SA queries\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|printf
argument_list|(
literal|"Large Path Record SA queries\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unknown value %u (ignored)\n"
argument_list|,
name|opt
operator|.
name|stress
argument_list|)
expr_stmt|;
name|opt
operator|.
name|stress
operator|=
literal|0
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'M'
case|:
comment|/* 			 * Perform multicast test. 			 */
name|opt
operator|.
name|mmode
operator|=
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tMulticast test enabled: "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|opt
operator|.
name|mmode
condition|)
block|{
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"Short MC Flow - single mode (default)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"Short MC Flow - multiple mode\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|printf
argument_list|(
literal|"Long MC Flow - single mode\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|printf
argument_list|(
literal|"Long MC Flow - multiple mode\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unknown value %u (ignored)\n"
argument_list|,
name|opt
operator|.
name|stress
argument_list|)
expr_stmt|;
name|opt
operator|.
name|mmode
operator|=
literal|0
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'d'
case|:
comment|/* 			 * Debug Options 			 */
name|printf
argument_list|(
literal|"\tDebug Option: "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
condition|)
block|{
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"Ignore Path Records\n"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|ignore_path_records
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"Force Log Flush\n"
argument_list|)
expr_stmt|;
name|opt
operator|.
name|force_log_flush
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* Used to be memory tracking */
default|default:
name|printf
argument_list|(
literal|"Unknown value %ld (ignored)\n"
argument_list|,
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'h'
case|:
name|show_usage
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
case|case
literal|'x'
case|:
name|log_flags
operator|=
name|strtol
argument_list|(
name|optarg
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t\t\t\tVerbose option -vf (log flags = 0x%X)\n"
argument_list|,
name|log_flags
argument_list|)
expr_stmt|;
break|break;
case|case
operator|-
literal|1
case|:
name|printf
argument_list|(
literal|"Done with args\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|show_usage
argument_list|()
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
do|while
condition|(
name|next_option
operator|!=
operator|-
literal|1
condition|)
do|;
name|printf
argument_list|(
literal|"\tFlow = %s\n"
argument_list|,
name|flow_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|vendor_debug
condition|)
name|osm_vendor_set_debug
argument_list|(
name|osm_test
operator|.
name|p_vendor
argument_list|,
name|vendor_debug
argument_list|)
expr_stmt|;
name|complib_init
argument_list|()
expr_stmt|;
name|status
operator|=
name|osmtest_init
argument_list|(
operator|&
name|osm_test
argument_list|,
operator|&
name|opt
argument_list|,
operator|(
name|osm_log_level_t
operator|)
name|log_flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|IB_SUCCESS
condition|)
block|{
name|printf
argument_list|(
literal|"\nError from osmtest_init: %s\n"
argument_list|,
name|ib_get_err_str
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|cl_hton64
argument_list|(
name|guid
argument_list|)
operator|==
name|cl_hton64
argument_list|(
name|INVALID_GUID
argument_list|)
condition|)
block|{
name|print_all_guids
argument_list|(
operator|&
name|osm_test
argument_list|)
expr_stmt|;
name|complib_exit
argument_list|()
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
comment|/* 	   If the user didn't specify a GUID on the command line, 	   then get a port GUID value with which to bind. 	 */
if|if
condition|(
name|guid
operator|==
literal|0
operator|&&
operator|!
operator|(
name|guid
operator|=
name|get_port_guid
argument_list|(
operator|&
name|osm_test
argument_list|,
name|guid
argument_list|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"\nError: port guid 0x%"
name|PRIx64
literal|" not found\n"
argument_list|,
name|guid
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* 	 * Guid may be zero going into this function if the user 	 * hasn't specified a binding port on the command line. 	 */
name|status
operator|=
name|osmtest_bind
argument_list|(
operator|&
name|osm_test
argument_list|,
name|max_lid
argument_list|,
name|guid
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|IB_SUCCESS
condition|)
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
name|status
operator|=
name|osmtest_run
argument_list|(
operator|&
name|osm_test
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|IB_SUCCESS
condition|)
block|{
name|printf
argument_list|(
literal|"OSMTEST: TEST \"%s\" FAIL\n"
argument_list|,
name|flow_name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"OSMTEST: TEST \"%s\" PASS\n"
argument_list|,
name|flow_name
argument_list|)
expr_stmt|;
block|}
name|osmtest_destroy
argument_list|(
operator|&
name|osm_test
argument_list|)
expr_stmt|;
name|complib_exit
argument_list|()
expr_stmt|;
name|Exit
label|:
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

end_unit

