begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2003  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REMOTE_EXT_H__
end_ifndef

begin_define
define|#
directive|define
name|__REMOTE_EXT_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REMOTE
end_ifndef

begin_error
error|#
directive|error
error|Please do not include this file directly. Just define HAVE_REMOTE and then include pcap.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*// Definition for Microsoft Visual Studio */
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1000
end_if

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * \file remote-ext.h  *  * The goal of this file it to include most of the new definitions that should be  * placed into the pcap.h file.  *  * It includes all new definitions (structures and functions like pcap_open().  * Some of the functions are not really a remote feature, but, right now,  * they are placed here.  */
comment|/*// All this stuff is public */
comment|/*  * \addtogroup remote_struct  * \{  */
comment|/*  * \brief Defines the maximum buffer size in which address, port, interface names are kept.  *  * In case the adapter name or such is larger than this value, it is truncated.  * This is not used by the user; however it must be aware that an hostname / interface  * name longer than this value will be truncated.  */
define|#
directive|define
name|PCAP_BUF_SIZE
value|1024
comment|/*  * \addtogroup remote_source_ID  * \{  */
comment|/*  * \brief Internal representation of the type of source in use (file,  * remote/local interface).  *  * This indicates a file, i.e. the user want to open a capture from a local file.  */
define|#
directive|define
name|PCAP_SRC_FILE
value|2
comment|/*  * \brief Internal representation of the type of source in use (file,  * remote/local interface).  *  * This indicates a local interface, i.e. the user want to open a capture from  * a local interface. This does not involve the RPCAP protocol.  */
define|#
directive|define
name|PCAP_SRC_IFLOCAL
value|3
comment|/*  * \brief Internal representation of the type of source in use (file,  * remote/local interface).  *  * This indicates a remote interface, i.e. the user want to open a capture from  * an interface on a remote host. This does involve the RPCAP protocol.  */
define|#
directive|define
name|PCAP_SRC_IFREMOTE
value|4
comment|/*  * \}  */
comment|/* \addtogroup remote_source_string  *  * The formats allowed by the pcap_open() are the following:  * - file://path_and_filename [opens a local file]  * - rpcap://devicename [opens the selected device devices available on the local host, without using the RPCAP protocol]  * - rpcap://host/devicename [opens the selected device available on a remote host]  * - rpcap://host:port/devicename [opens the selected device available on a remote host, using a non-standard port for RPCAP]  * - adaptername [to open a local adapter; kept for compability, but it is strongly discouraged]  * - (NULL) [to open the first local adapter; kept for compability, but it is strongly discouraged]  *  * The formats allowed by the pcap_findalldevs_ex() are the following:  * - file://folder/ [lists all the files in the given folder]  * - rpcap:// [lists all local adapters]  * - rpcap://host:port/ [lists the devices available on a remote host]  *  * Referring to the 'host' and 'port' parameters, they can be either numeric or literal. Since  * IPv6 is fully supported, these are the allowed formats:  *  * - host (literal): e.g. host.foo.bar  * - host (numeric IPv4): e.g. 10.11.12.13  * - host (numeric IPv4, IPv6 style): e.g. [10.11.12.13]  * - host (numeric IPv6): e.g. [1:2:3::4]  * - port: can be either numeric (e.g. '80') or literal (e.g. 'http')  *  * Here you find some allowed examples:  * - rpcap://host.foo.bar/devicename [everything literal, no port number]  * - rpcap://host.foo.bar:1234/devicename [everything literal, with port number]  * - rpcap://10.11.12.13/devicename [IPv4 numeric, no port number]  * - rpcap://10.11.12.13:1234/devicename [IPv4 numeric, with port number]  * - rpcap://[10.11.12.13]:1234/devicename [IPv4 numeric with IPv6 format, with port number]  * - rpcap://[1:2:3::4]/devicename [IPv6 numeric, no port number]  * - rpcap://[1:2:3::4]:1234/devicename [IPv6 numeric, with port number]  * - rpcap://[1:2:3::4]:http/devicename [IPv6 numeric, with literal port number]  *  * \{  */
comment|/*  * \brief String that will be used to determine the type of source in use (file,  * remote/local interface).  *  * This string will be prepended to the interface name in order to create a string  * that contains all the information required to open the source.  *  * This string indicates that the user wants to open a capture from a local file.  */
define|#
directive|define
name|PCAP_SRC_FILE_STRING
value|"file://"
comment|/*  * \brief String that will be used to determine the type of source in use (file,  * remote/local interface).  *  * This string will be prepended to the interface name in order to create a string  * that contains all the information required to open the source.  *  * This string indicates that the user wants to open a capture from a network interface.  * This string does not necessarily involve the use of the RPCAP protocol. If the  * interface required resides on the local host, the RPCAP protocol is not involved  * and the local functions are used.  */
define|#
directive|define
name|PCAP_SRC_IF_STRING
value|"rpcap://"
comment|/*  * \}  */
comment|/*  * \addtogroup remote_open_flags  * \{  */
comment|/*  * \brief Defines if the adapter has to go in promiscuous mode.  *  * It is '1' if you have to open the adapter in promiscuous mode, '0' otherwise.  * Note that even if this parameter is false, the interface could well be in promiscuous  * mode for some other reason (for example because another capture process with  * promiscuous mode enabled is currently using that interface).  * On on Linux systems with 2.2 or later kernels (that have the "any" device), this  * flag does not work on the "any" device; if an argument of "any" is supplied,  * the 'promisc' flag is ignored.  */
define|#
directive|define
name|PCAP_OPENFLAG_PROMISCUOUS
value|1
comment|/*  * \brief Defines if the data transfer (in case of a remote  * capture) has to be done with UDP protocol.  *  * If it is '1' if you want a UDP data connection, '0' if you want  * a TCP data connection; control connection is always TCP-based.  * A UDP connection is much lighter, but it does not guarantee that all  * the captured packets arrive to the client workstation. Moreover,  * it could be harmful in case of network congestion.  * This flag is meaningless if the source is not a remote interface.  * In that case, it is simply ignored.  */
define|#
directive|define
name|PCAP_OPENFLAG_DATATX_UDP
value|2
comment|/*  * \brief Defines if the remote probe will capture its own generated traffic.  *  * In case the remote probe uses the same interface to capture traffic and to send  * data back to the caller, the captured traffic includes the RPCAP traffic as well.  * If this flag is turned on, the RPCAP traffic is excluded from the capture, so that  * the trace returned back to the collector is does not include this traffic.  */
define|#
directive|define
name|PCAP_OPENFLAG_NOCAPTURE_RPCAP
value|4
comment|/*  * \brief Defines if the local adapter will capture its own generated traffic.  *  * This flag tells the underlying capture driver to drop the packets that were sent by itself.  * This is useful when building applications like bridges, that should ignore the traffic  * they just sent.  */
define|#
directive|define
name|PCAP_OPENFLAG_NOCAPTURE_LOCAL
value|8
comment|/*  * \brief This flag configures the adapter for maximum responsiveness.  *  * In presence of a large value for nbytes, WinPcap waits for the arrival of several packets before  * copying the data to the user. This guarantees a low number of system calls, i.e. lower processor usage,  * i.e. better performance, which is good for applications like sniffers. If the user sets the  * PCAP_OPENFLAG_MAX_RESPONSIVENESS flag, the capture driver will copy the packets as soon as the application  * is ready to receive them. This is suggested for real time applications (like, for example, a bridge)  * that need the best responsiveness.  */
define|#
directive|define
name|PCAP_OPENFLAG_MAX_RESPONSIVENESS
value|16
comment|/*  * \}  */
comment|/*  * \addtogroup remote_samp_methods  * \{  */
comment|/*  *\brief No sampling has to be done on the current capture.  *  * In this case, no sampling algorithms are applied to the current capture.  */
define|#
directive|define
name|PCAP_SAMP_NOSAMP
value|0
comment|/*  * \brief It defines that only 1 out of N packets must be returned to the user.  *  * In this case, the 'value' field of the 'pcap_samp' structure indicates the  * number of packets (minus 1) that must be discarded before one packet got accepted.  * In other words, if 'value = 10', the first packet is returned to the caller, while  * the following 9 are discarded.  */
define|#
directive|define
name|PCAP_SAMP_1_EVERY_N
value|1
comment|/*  * \brief It defines that we have to return 1 packet every N milliseconds.  *  * In this case, the 'value' field of the 'pcap_samp' structure indicates the 'waiting  * time' in milliseconds before one packet got accepted.  * In other words, if 'value = 10', the first packet is returned to the caller; the next  * returned one will be the first packet that arrives when 10ms have elapsed.  */
define|#
directive|define
name|PCAP_SAMP_FIRST_AFTER_N_MS
value|2
comment|/*  * \}  */
comment|/*  * \addtogroup remote_auth_methods  * \{  */
comment|/*  * \brief It defines the NULL authentication.  *  * This value has to be used within the 'type' member of the pcap_rmtauth structure.  * The 'NULL' authentication has to be equal to 'zero', so that old applications  * can just put every field of struct pcap_rmtauth to zero, and it does work.  */
define|#
directive|define
name|RPCAP_RMTAUTH_NULL
value|0
comment|/*  * \brief It defines the username/password authentication.  *  * With this type of authentication, the RPCAP protocol will use the username/  * password provided to authenticate the user on the remote machine. If the  * authentication is successful (and the user has the right to open network devices)  * the RPCAP connection will continue; otherwise it will be dropped.  *  * This value has to be used within the 'type' member of the pcap_rmtauth structure.  */
define|#
directive|define
name|RPCAP_RMTAUTH_PWD
value|1
comment|/*  * \}  */
comment|/*  * \brief This structure keeps the information needed to autheticate  * the user on a remote machine.  *  * The remote machine can either grant or refuse the access according  * to the information provided.  * In case the NULL authentication is required, both 'username' and  * 'password' can be NULL pointers.  *  * This structure is meaningless if the source is not a remote interface;  * in that case, the functions which requires such a structure can accept  * a NULL pointer as well.  */
struct|struct
name|pcap_rmtauth
block|{
comment|/* 	 * \brief Type of the authentication required. 	 * 	 * In order to provide maximum flexibility, we can support different types 	 * of authentication based on the value of this 'type' variable. The currently 	 * supported authentication methods are defined into the 	 * \link remote_auth_methods Remote Authentication Methods Section\endlink. 	 */
name|int
name|type
decl_stmt|;
comment|/* 	 * \brief Zero-terminated string containing the username that has to be 	 * used on the remote machine for authentication. 	 * 	 * This field is meaningless in case of the RPCAP_RMTAUTH_NULL authentication 	 * and it can be NULL. 	 */
name|char
modifier|*
name|username
decl_stmt|;
comment|/* 	 * \brief Zero-terminated string containing the password that has to be 	 * used on the remote machine for authentication. 	 * 	 * This field is meaningless in case of the RPCAP_RMTAUTH_NULL authentication 	 * and it can be NULL. 	 */
name|char
modifier|*
name|password
decl_stmt|;
block|}
struct|;
comment|/*  * \brief This structure defines the information related to sampling.  *  * In case the sampling is requested, the capturing device should read  * only a subset of the packets coming from the source. The returned packets depend  * on the sampling parameters.  *  * \warning The sampling process is applied<strong>after</strong> the filtering process.  * In other words, packets are filtered first, then the sampling process selects a  * subset of the 'filtered' packets and it returns them to the caller.  */
struct|struct
name|pcap_samp
block|{
comment|/* 	 * Method used for sampling. Currently, the supported methods are listed in the 	 * \link remote_samp_methods Sampling Methods Section\endlink. 	 */
name|int
name|method
decl_stmt|;
comment|/* 	 * This value depends on the sampling method defined. For its meaning, please check 	 * at the \link remote_samp_methods Sampling Methods Section\endlink. 	 */
name|int
name|value
decl_stmt|;
block|}
struct|;
comment|// Maximum length of an host name (needed for the RPCAP active mode)
define|#
directive|define
name|RPCAP_HOSTLIST_SIZE
value|1024
comment|/*  * \}  */
comment|// end of public documentation
comment|// Exported functions
comment|/*  * \name New WinPcap functions  *  * This section lists the new functions that are able to help considerably in writing  * WinPcap programs because of their easiness of use.  */
comment|// \{
name|PCAP_API
name|pcap_t
modifier|*
name|pcap_open
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|int
name|snaplen
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|read_timeout
parameter_list|,
name|struct
name|pcap_rmtauth
modifier|*
name|auth
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|int
name|pcap_createsrcstr
parameter_list|(
name|char
modifier|*
name|source
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|port
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|int
name|pcap_parsesrcstr
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|int
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|port
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|int
name|pcap_findalldevs_ex
parameter_list|(
name|char
modifier|*
name|source
parameter_list|,
name|struct
name|pcap_rmtauth
modifier|*
name|auth
parameter_list|,
name|pcap_if_t
modifier|*
modifier|*
name|alldevs
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|struct
name|pcap_samp
modifier|*
name|pcap_setsampling
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// \}
comment|// End of new WinPcap functions
comment|/*  * \name Remote Capture functions  */
comment|/*  * Some minor differences between UN*X sockets and and Winsock sockets.  */
ifndef|#
directive|ifndef
name|_WIN32
comment|/*!    * \brief In Winsock, a socket handle is of type SOCKET; in UN*X, it's    * a file descriptor, and therefore a signed integer.    * We define SOCKET to be a signed integer on UN*X, so that it can    * be used on both platforms.    */
define|#
directive|define
name|SOCKET
value|int
comment|/*!    * \brief In Winsock, the error return if socket() fails is INVALID_SOCKET;    * in UN*X, it's -1.    * We define INVALID_SOCKET to be -1 on UN*X, so that it can be used on    * both platforms.    */
define|#
directive|define
name|INVALID_SOCKET
value|-1
endif|#
directive|endif
comment|// \{
name|PCAP_API
name|SOCKET
name|pcap_remoteact_accept
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
specifier|const
name|char
modifier|*
name|port
parameter_list|,
specifier|const
name|char
modifier|*
name|hostlist
parameter_list|,
name|char
modifier|*
name|connectinghost
parameter_list|,
name|struct
name|pcap_rmtauth
modifier|*
name|auth
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|int
name|pcap_remoteact_list
parameter_list|(
name|char
modifier|*
name|hostlist
parameter_list|,
name|char
name|sep
parameter_list|,
name|int
name|size
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|int
name|pcap_remoteact_close
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
name|PCAP_API
name|void
name|pcap_remoteact_cleanup
parameter_list|()
function_decl|;
comment|// \}
comment|// End of remote capture functions
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

end_unit

