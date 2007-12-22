begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * NetWare requestor error codes, they taken from NDK  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NWERROR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NWERROR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SHELL_ERROR
value|0x8800
end_define

begin_define
define|#
directive|define
name|VLM_ERROR
value|0x8800
end_define

begin_define
define|#
directive|define
name|ALREADY_ATTACHED
value|0x8800
end_define

begin_comment
comment|/* 0  - Attach attempted to server with valid, existing connection */
end_comment

begin_define
define|#
directive|define
name|INVALID_CONNECTION
value|0x8801
end_define

begin_comment
comment|/* 1  - Request attempted with invalid or non-attached connection handle */
end_comment

begin_define
define|#
directive|define
name|DRIVE_IN_USE
value|0x8802
end_define

begin_comment
comment|/* 2  - OS/2 only (NOT USED) */
end_comment

begin_define
define|#
directive|define
name|CANT_ADD_CDS
value|0x8803
end_define

begin_comment
comment|/* 3  - Map drive attempted but unable to add new current directory structure */
end_comment

begin_define
define|#
directive|define
name|DRIVE_CANNOT_MAP
value|0x8803
end_define

begin_define
define|#
directive|define
name|BAD_DRIVE_BASE
value|0x8804
end_define

begin_comment
comment|/* 4  - Map drive attempted with invalid path specification */
end_comment

begin_define
define|#
directive|define
name|NET_READ_ERROR
value|0x8805
end_define

begin_comment
comment|/* 5  - Attempt to receive from the selected transport failed */
end_comment

begin_define
define|#
directive|define
name|NET_RECV_ERROR
value|0x8805
end_define

begin_comment
comment|/* 5  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_NET_ERROR
value|0x8806
end_define

begin_comment
comment|/* 6  - Network send attempted with an un-specific network error */
end_comment

begin_define
define|#
directive|define
name|SERVER_INVALID_SLOT
value|0x8807
end_define

begin_comment
comment|/* 7  - Server request attempted with invalid server connection slot */
end_comment

begin_define
define|#
directive|define
name|BAD_SERVER_SLOT
value|0x8807
end_define

begin_comment
comment|/* 7  */
end_comment

begin_define
define|#
directive|define
name|NO_SERVER_SLOTS
value|0x8808
end_define

begin_comment
comment|/* 8  - Attach attempted to server with no connection slots available */
end_comment

begin_define
define|#
directive|define
name|NET_WRITE_ERROR
value|0x8809
end_define

begin_comment
comment|/* 9  - Attempt to send on the selected transport failed */
end_comment

begin_define
define|#
directive|define
name|CONNECTION_IN_ERROR_STATE
value|0x8809
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_SEND_ERROR
value|0x8809
end_define

begin_comment
comment|/* 9  */
end_comment

begin_define
define|#
directive|define
name|SERVER_NO_ROUTE
value|0x880A
end_define

begin_comment
comment|/* 10 - Attempted to find route to server where no route exists */
end_comment

begin_define
define|#
directive|define
name|BAD_LOCAL_TARGET
value|0x880B
end_define

begin_comment
comment|/* 11 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|TOO_MANY_REQ_FRAGS
value|0x880C
end_define

begin_comment
comment|/* 12 - Attempted request with too many request fragments specified */
end_comment

begin_define
define|#
directive|define
name|CONNECT_LIST_OVERFLOW
value|0x880D
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|BUFFER_OVERFLOW
value|0x880E
end_define

begin_comment
comment|/* 14 - Attempt to receive more data than the reply buffer had room for */
end_comment

begin_define
define|#
directive|define
name|MORE_DATA_ERROR
value|0x880E
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NO_CONN_TO_SERVER
value|0x880F
end_define

begin_comment
comment|/* 15 */
end_comment

begin_define
define|#
directive|define
name|NO_CONNECTION_TO_SERVER
value|0x880F
end_define

begin_comment
comment|/* 15 - Attempt to get connection for a server not connected */
end_comment

begin_define
define|#
directive|define
name|NO_ROUTER_FOUND
value|0x8810
end_define

begin_comment
comment|/* 16 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|BAD_FUNC_ERROR
value|0x8811
end_define

begin_comment
comment|/* 17 */
end_comment

begin_define
define|#
directive|define
name|INVALID_SHELL_CALL
value|0x8811
end_define

begin_comment
comment|/* 17 - Attempted function call to non- existent or illegal function */
end_comment

begin_define
define|#
directive|define
name|SCAN_COMPLETE
value|0x8812
end_define

begin_define
define|#
directive|define
name|LIP_RESIZE_ERROR
value|0x8812
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|UNSUPPORTED_NAME_FORMAT_TYPE
value|0x8813
end_define

begin_define
define|#
directive|define
name|INVALID_DIR_HANDLE
value|0x8813
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|HANDLE_ALREADY_LICENSED
value|0x8814
end_define

begin_define
define|#
directive|define
name|OUT_OF_CLIENT_MEMORY
value|0x8814
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|HANDLE_ALREADY_UNLICENSED
value|0x8815
end_define

begin_define
define|#
directive|define
name|PATH_NOT_OURS
value|0x8815
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|INVALID_NCP_PACKET_LENGTH
value|0x8816
end_define

begin_define
define|#
directive|define
name|PATH_IS_PRINT_DEVICE
value|0x8816
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SETTING_UP_TIMEOUT
value|0x8817
end_define

begin_define
define|#
directive|define
name|PATH_IS_EXCLUDED_DEVICE
value|0x8817
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SETTING_SIGNALS
value|0x8818
end_define

begin_define
define|#
directive|define
name|PATH_IS_INVALID
value|0x8818
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SERVER_CONNECTION_LOST
value|0x8819
end_define

begin_define
define|#
directive|define
name|NOT_SAME_DEVICE
value|0x8819
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|OUT_OF_HEAP_SPACE
value|0x881A
end_define

begin_define
define|#
directive|define
name|INVALID_SERVICE_REQUEST
value|0x881B
end_define

begin_define
define|#
directive|define
name|INVALID_SEARCH_HANDLE
value|0x881B
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|INVALID_TASK_NUMBER
value|0x881C
end_define

begin_define
define|#
directive|define
name|INVALID_DEVICE_HANDLE
value|0x881C
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|INVALID_MESSAGE_LENGTH
value|0x881D
end_define

begin_define
define|#
directive|define
name|INVALID_SEM_HANDLE
value|0x881D
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|EA_SCAN_DONE
value|0x881E
end_define

begin_define
define|#
directive|define
name|INVALID_CFG_HANDLE
value|0x881E
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|BAD_CONNECTION_NUMBER
value|0x881F
end_define

begin_define
define|#
directive|define
name|INVALID_MOD_HANDLE
value|0x881F
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|ASYN_FIRST_PASS
value|0x8820
end_define

begin_define
define|#
directive|define
name|INVALID_DEVICE_INDEX
value|0x8821
end_define

begin_define
define|#
directive|define
name|INVALID_CONN_HANDLE
value|0x8822
end_define

begin_define
define|#
directive|define
name|INVALID_QUEUE_ID
value|0x8823
end_define

begin_define
define|#
directive|define
name|INVALID_PDEVICE_HANDLE
value|0x8824
end_define

begin_define
define|#
directive|define
name|INVALID_JOB_HANDLE
value|0x8825
end_define

begin_define
define|#
directive|define
name|INVALID_ELEMENT_ID
value|0x8826
end_define

begin_define
define|#
directive|define
name|ALIAS_NOT_FOUND
value|0x8827
end_define

begin_define
define|#
directive|define
name|RESOURCE_SUSPENDED
value|0x8828
end_define

begin_define
define|#
directive|define
name|INVALID_QUEUE_SPECIFIED
value|0x8829
end_define

begin_define
define|#
directive|define
name|DEVICE_ALREADY_OPEN
value|0x882A
end_define

begin_define
define|#
directive|define
name|JOB_ALREADY_OPEN
value|0x882B
end_define

begin_define
define|#
directive|define
name|QUEUE_NAME_ID_MISMATCH
value|0x882C
end_define

begin_define
define|#
directive|define
name|JOB_ALREADY_STARTED
value|0x882D
end_define

begin_define
define|#
directive|define
name|SPECT_DAA_TYPE_NOT_SUPPORTED
value|0x882E
end_define

begin_define
define|#
directive|define
name|INVALID_ENVIR_HANDLE
value|0x882F
end_define

begin_define
define|#
directive|define
name|NOT_SAME_CONNECTION
value|0x8830
end_define

begin_comment
comment|/* 48 - Internal server request attempted accross different server connections */
end_comment

begin_define
define|#
directive|define
name|PRIMARY_CONNECTION_NOT_SET
value|0x8831
end_define

begin_comment
comment|/* 49 - Attempt to retrieve default connection with no primary connection set */
end_comment

begin_define
define|#
directive|define
name|NO_PRIMARY_SET
value|0x8831
end_define

begin_comment
comment|/* 49 */
end_comment

begin_define
define|#
directive|define
name|KEYWORD_NOT_FOUND
value|0x8832
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|PRINT_CAPTURE_NOT_IN_PROGRESS
value|0x8832
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NO_CAPTURE_SET
value|0x8832
end_define

begin_comment
comment|/* 50 */
end_comment

begin_define
define|#
directive|define
name|NO_CAPTURE_IN_PROGRESS
value|0x8832
end_define

begin_comment
comment|/* 50 - Capture information requested on port with no capture in progress */
end_comment

begin_define
define|#
directive|define
name|BAD_BUFFER_LENGTH
value|0x8833
end_define

begin_comment
comment|/* 51 */
end_comment

begin_define
define|#
directive|define
name|INVALID_BUFFER_LENGTH
value|0x8833
end_define

begin_comment
comment|/* 51 - Used to indicate length which caller requested on a GetDNC or SetDNC was too large */
end_comment

begin_define
define|#
directive|define
name|NO_USER_NAME
value|0x8834
end_define

begin_comment
comment|/* 52 */
end_comment

begin_define
define|#
directive|define
name|NO_NETWARE_PRINT_SPOOLER
value|0x8835
end_define

begin_comment
comment|/* 53 - Capture requested without having the local print spooler installed */
end_comment

begin_define
define|#
directive|define
name|INVALID_PARAMETER
value|0x8836
end_define

begin_comment
comment|/* 54 - Attempted function with an invalid function parameter specified */
end_comment

begin_define
define|#
directive|define
name|CONFIG_FILE_OPEN_FAILED
value|0x8837
end_define

begin_comment
comment|/* 55 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NO_CONFIG_FILE
value|0x8838
end_define

begin_comment
comment|/* 56 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|CONFIG_FILE_READ_FAILED
value|0x8839
end_define

begin_comment
comment|/* 57 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|CONFIG_LINE_TOO_LONG
value|0x883A
end_define

begin_comment
comment|/* 58 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|CONFIG_LINES_IGNORED
value|0x883B
end_define

begin_comment
comment|/* 59 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NOT_MY_RESOURCE
value|0x883C
end_define

begin_comment
comment|/* 60 - Attempted request made with a parameter using foriegn resource */
end_comment

begin_define
define|#
directive|define
name|DAEMON_INSTALLED
value|0x883D
end_define

begin_comment
comment|/* 61 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|SPOOLER_INSTALLED
value|0x883E
end_define

begin_comment
comment|/* 62 - Attempted load of print spooler with print spooler already installed */
end_comment

begin_define
define|#
directive|define
name|CONN_TABLE_FULL
value|0x883F
end_define

begin_comment
comment|/* 63 */
end_comment

begin_define
define|#
directive|define
name|CONNECTION_TABLE_FULL
value|0x883F
end_define

begin_comment
comment|/* 63 - Attempted to allocate a connection handle with no more local connection table entries */
end_comment

begin_define
define|#
directive|define
name|CONFIG_SECTION_NOT_FOUND
value|0x8840
end_define

begin_comment
comment|/* 64 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|BAD_TRAN_TYPE
value|0x8841
end_define

begin_comment
comment|/* 65 */
end_comment

begin_define
define|#
directive|define
name|INVALID_TRANSPORT_TYPE
value|0x8841
end_define

begin_comment
comment|/* 65 - Attempted function on a connection with an invalid transport selected */
end_comment

begin_define
define|#
directive|define
name|TDS_TAG_IN_USE
value|0x8842
end_define

begin_comment
comment|/* 66 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|TDS_OUT_OF_MEMORY
value|0x8843
end_define

begin_comment
comment|/* 67 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|TDS_INVALID_TAG
value|0x8844
end_define

begin_comment
comment|/* 68 - Attempted TDS function with invalid tag */
end_comment

begin_define
define|#
directive|define
name|TDS_WRITE_TRUNCATED
value|0x8845
end_define

begin_comment
comment|/* 69 - Attempted TDS write with buffer that exceeded buffer */
end_comment

begin_define
define|#
directive|define
name|NO_CONNECTION_TO_DS
value|0x8846
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NO_DIRECTORY_SERVICE_CONNECTION
value|0x8846
end_define

begin_comment
comment|/* 70 */
end_comment

begin_define
define|#
directive|define
name|SERVICE_BUSY
value|0x8846
end_define

begin_comment
comment|/* 70 - Attempted request made to partially asynchronous function in busy state */
end_comment

begin_define
define|#
directive|define
name|NO_SERVER_ERROR
value|0x8847
end_define

begin_comment
comment|/* 71 - Attempted connect failed to find any servers responding */
end_comment

begin_define
define|#
directive|define
name|BAD_VLM_ERROR
value|0x8848
end_define

begin_comment
comment|/* 72 - Attempted function call to non-existant or not-loaded overlay */
end_comment

begin_define
define|#
directive|define
name|NETWORK_DRIVE_IN_USE
value|0x8849
end_define

begin_comment
comment|/* 73 - Attempted map to network drive that was already mapped */
end_comment

begin_define
define|#
directive|define
name|LOCAL_DRIVE_IN_USE
value|0x884A
end_define

begin_comment
comment|/* 74 - Attempted map to local drive that was in use */
end_comment

begin_define
define|#
directive|define
name|NO_DRIVES_AVAILABLE
value|0x884B
end_define

begin_comment
comment|/* 75 - Attempted map to next available drive when none were available */
end_comment

begin_define
define|#
directive|define
name|DEVICE_NOT_REDIRECTED
value|0x884C
end_define

begin_comment
comment|/* 76 - The device is not redirected */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_SFT_ENTRIES
value|0x884D
end_define

begin_comment
comment|/* 77 - Maximum number of files was reached */
end_comment

begin_define
define|#
directive|define
name|UNLOAD_ERROR
value|0x884E
end_define

begin_comment
comment|/* 78 - Attempted unload failed */
end_comment

begin_define
define|#
directive|define
name|IN_USE_ERROR
value|0x884F
end_define

begin_comment
comment|/* 79 - Attempted re-use of already in use connection entry */
end_comment

begin_define
define|#
directive|define
name|TOO_MANY_REP_FRAGS
value|0x8850
end_define

begin_comment
comment|/* 80 - Attempted request with too many reply fragments specified */
end_comment

begin_define
define|#
directive|define
name|TABLE_FULL
value|0x8851
end_define

begin_comment
comment|/* 81 - Attempted to add a name into the name table after it was full */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKET_NOT_OPEN
end_ifndef

begin_define
define|#
directive|define
name|SOCKET_NOT_OPEN
value|0x8852
end_define

begin_comment
comment|/* 82 - Listen was posted on unopened socket */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEM_MGR_ERROR
value|0x8853
end_define

begin_comment
comment|/* 83 - Attempted enhanced memory operation failed */
end_comment

begin_define
define|#
directive|define
name|SFT3_ERROR
value|0x8854
end_define

begin_comment
comment|/* 84 - An SFT3 switch occured mid-transfer */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_NOT_FOUND
value|0x8855
end_define

begin_comment
comment|/* 85 - the preferred directory server was not established but another directory server was returned */
end_comment

begin_define
define|#
directive|define
name|DEVICE_NOT_RECOGNIZED
value|0x8856
end_define

begin_comment
comment|/* 86 - used to determine if the device is not used by VISE so pass it on to the next redirector, if any. */
end_comment

begin_define
define|#
directive|define
name|BAD_NET_TYPE
value|0x8857
end_define

begin_comment
comment|/* 87 - the network type (Bind/NDS) does not match the server version */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPENING_FILE
value|0x8858
end_define

begin_comment
comment|/* 88 - generic open failure error, invalid path, access denied, etc.. */
end_comment

begin_define
define|#
directive|define
name|NO_PREFERRED_SPECIFIED
value|0x8859
end_define

begin_comment
comment|/* 89 - no preferred name specified */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPENING_SOCKET
value|0x885A
end_define

begin_comment
comment|/* 90 - error opening a socket */
end_comment

begin_define
define|#
directive|define
name|REQUESTER_FAILURE
value|0x885A
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_ACCESS_DENIED
value|0x885B
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_LEVEL_CONFLICT
value|0x8861
end_define

begin_define
define|#
directive|define
name|NO_LOCK_FOUND
value|0x8862
end_define

begin_comment
comment|/* OS/2 - process lock on conn handle failed, process ID not recognized */
end_comment

begin_define
define|#
directive|define
name|LOCK_TABLE_FULL
value|0x8863
end_define

begin_comment
comment|/* OS/2 - process lock on conn handle failed, process lock table full */
end_comment

begin_define
define|#
directive|define
name|INVALID_MATCH_DATA
value|0x8864
end_define

begin_define
define|#
directive|define
name|MATCH_FAILED
value|0x8865
end_define

begin_define
define|#
directive|define
name|NO_MORE_ENTRIES
value|0x8866
end_define

begin_define
define|#
directive|define
name|INSUFFICIENT_RESOURCES
value|0x8867
end_define

begin_define
define|#
directive|define
name|STRING_TRANSLATION
value|0x8868
end_define

begin_define
define|#
directive|define
name|STRING_TRANSLATION_NEEDED
value|0x8868
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|ACCESS_VIOLATION
value|0x8869
end_define

begin_define
define|#
directive|define
name|NOT_AUTHENTICATED
value|0x886A
end_define

begin_define
define|#
directive|define
name|INVALID_LEVEL
value|0x886B
end_define

begin_define
define|#
directive|define
name|RESOURCE_LOCK_ERROR
value|0x886C
end_define

begin_define
define|#
directive|define
name|INVALID_NAME_FORMAT
value|0x886D
end_define

begin_define
define|#
directive|define
name|OBJECT_EXISTS
value|0x886E
end_define

begin_define
define|#
directive|define
name|OBJECT_NOT_FOUND
value|0x886F
end_define

begin_define
define|#
directive|define
name|UNSUPPORTED_TRAN_TYPE
value|0x8870
end_define

begin_define
define|#
directive|define
name|INVALID_STRING_TYPE
value|0x8871
end_define

begin_define
define|#
directive|define
name|INVALID_OWNER
value|0x8872
end_define

begin_define
define|#
directive|define
name|UNSUPPORTED_AUTHENTICATOR
value|0x8873
end_define

begin_define
define|#
directive|define
name|IO_PENDING
value|0x8874
end_define

begin_define
define|#
directive|define
name|INVALID_DRIVE_NUM
value|0x8875
end_define

begin_define
define|#
directive|define
name|SHELL_FAILURE
value|0x88FF
end_define

begin_define
define|#
directive|define
name|VLM_FAILURE
value|0x88FF
end_define

begin_define
define|#
directive|define
name|SVC_ALREADY_REGISTERED
value|0x8880
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SVC_REGISTRY_FULL
value|0x8881
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SVC_NOT_REGISTERED
value|0x8882
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|OUT_OF_RESOURCES
value|0x8883
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|RESOLVE_SVC_FAILED
value|0x8884
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|CONNECT_FAILED
value|0x8885
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_NOT_BOUND
value|0x8886
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTHENTICATION_FAILED
value|0x8887
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|INVALID_AUTHEN_HANDLE
value|0x8888
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTHEN_HANDLE_ALREADY_EXISTS
value|0x8889
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|DIFF_OBJECT_ALREADY_AUTHEN
value|0x8890
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|REQUEST_NOT_SERVICEABLE
value|0x8891
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTO_RECONNECT_SO_REBUILD
value|0x8892
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTO_RECONNECT_RETRY_REQUEST
value|0x8893
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|ASYNC_REQUEST_IN_USE
value|0x8894
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|ASYNC_REQUEST_CANCELED
value|0x8895
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SESS_SVC_ALREADY_REGISTERED
value|0x8896
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|SESS_SVC_NOT_REGISTERED
value|0x8897
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|PREVIOUSLY_AUTHENTICATED
value|0x8899
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|RESOLVE_SVC_PARTIAL
value|0x889A
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NO_DEFAULT_SPECIFIED
value|0x889B
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|HOOK_REQUEST_NOT_HANDLED
value|0x889C
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|HOOK_REQUEST_BUSY
value|0x889D
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|HOOK_REQUEST_QUEUED
value|0x889D
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTO_RECONNECT_SO_IGNORE
value|0x889E
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|ASYNC_REQUEST_NOT_IN_USE
value|0x889F
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|AUTO_RECONNECT_FAILURE
value|0x88A0
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_ERROR_ABORT_APPLICATION
value|0x88A1
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_ERROR_SUSPEND_APPLICATION
value|0x88A2
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_ERROR_ABORTED_PROCESS_GROUP
value|0x88A3
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_ERROR_PASSWORD_HAS_EXPIRED
value|0x88A5
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|NET_ERROR_NETWORK_INACTIVE
value|0x88A6
end_define

begin_comment
comment|/* Client-32 */
end_comment

begin_define
define|#
directive|define
name|REPLY_TRUNCATED
value|0x88e6
end_define

begin_comment
comment|/* 230 NLM */
end_comment

begin_comment
comment|/* Server Errors */
end_comment

begin_define
define|#
directive|define
name|ERR_INSUFFICIENT_SPACE
value|0x8901
end_define

begin_comment
comment|/* 001 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_MORE_ENTRY
value|0x8914
end_define

begin_comment
comment|/* 020 */
end_comment

begin_define
define|#
directive|define
name|NLM_INVALID_CONNECTION
value|0x890a
end_define

begin_comment
comment|/* 010 */
end_comment

begin_define
define|#
directive|define
name|ERR_BUFFER_TOO_SMALL
value|0x8977
end_define

begin_comment
comment|/* 119 */
end_comment

begin_define
define|#
directive|define
name|ERR_VOLUME_FLAG_NOT_SET
value|0x8978
end_define

begin_comment
comment|/* 120 the service requested, not avail. on the selected vol. */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_ITEMS_FOUND
value|0x8979
end_define

begin_comment
comment|/* 121 */
end_comment

begin_define
define|#
directive|define
name|ERR_CONN_ALREADY_TEMP
value|0x897a
end_define

begin_comment
comment|/* 122 */
end_comment

begin_define
define|#
directive|define
name|ERR_CONN_ALREADY_LOGGED_IN
value|0x897b
end_define

begin_comment
comment|/* 123 */
end_comment

begin_define
define|#
directive|define
name|ERR_CONN_NOT_AUTHENTICATED
value|0x897c
end_define

begin_comment
comment|/* 124 */
end_comment

begin_define
define|#
directive|define
name|ERR_CONN_NOT_LOGGED_IN
value|0x897d
end_define

begin_comment
comment|/* 125 */
end_comment

begin_define
define|#
directive|define
name|NCP_BOUNDARY_CHECK_FAILED
value|0x897e
end_define

begin_comment
comment|/* 126 */
end_comment

begin_define
define|#
directive|define
name|ERR_LOCK_WAITING
value|0x897f
end_define

begin_comment
comment|/* 127 */
end_comment

begin_define
define|#
directive|define
name|ERR_LOCK_FAIL
value|0x8980
end_define

begin_comment
comment|/* 128 */
end_comment

begin_define
define|#
directive|define
name|FILE_IN_USE_ERROR
value|0x8980
end_define

begin_comment
comment|/* 128 */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_FILE_HANDLES
value|0x8981
end_define

begin_comment
comment|/* 129 */
end_comment

begin_define
define|#
directive|define
name|NO_OPEN_PRIVILEGES
value|0x8982
end_define

begin_comment
comment|/* 130 */
end_comment

begin_define
define|#
directive|define
name|IO_ERROR_NETWORK_DISK
value|0x8983
end_define

begin_comment
comment|/* 131 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_HARD_IO_ERROR
value|0x8983
end_define

begin_comment
comment|/* 131 */
end_comment

begin_define
define|#
directive|define
name|NO_CREATE_PRIVILEGES
value|0x8984
end_define

begin_comment
comment|/* 132 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_NOT_SUPV
value|0x8984
end_define

begin_comment
comment|/* 132 */
end_comment

begin_define
define|#
directive|define
name|NO_CREATE_DELETE_PRIVILEGES
value|0x8985
end_define

begin_comment
comment|/* 133 */
end_comment

begin_define
define|#
directive|define
name|CREATE_FILE_EXISTS_READ_ONLY
value|0x8986
end_define

begin_comment
comment|/* 134 */
end_comment

begin_define
define|#
directive|define
name|WILD_CARDS_IN_CREATE_FILE_NAME
value|0x8987
end_define

begin_comment
comment|/* 135 */
end_comment

begin_define
define|#
directive|define
name|CREATE_FILENAME_ERROR
value|0x8987
end_define

begin_comment
comment|/* 135 */
end_comment

begin_define
define|#
directive|define
name|INVALID_FILE_HANDLE
value|0x8988
end_define

begin_comment
comment|/* 136 */
end_comment

begin_define
define|#
directive|define
name|NO_SEARCH_PRIVILEGES
value|0x8989
end_define

begin_comment
comment|/* 137 */
end_comment

begin_define
define|#
directive|define
name|NO_DELETE_PRIVILEGES
value|0x898A
end_define

begin_comment
comment|/* 138 */
end_comment

begin_define
define|#
directive|define
name|NO_RENAME_PRIVILEGES
value|0x898B
end_define

begin_comment
comment|/* 139 */
end_comment

begin_define
define|#
directive|define
name|NO_MODIFY_PRIVILEGES
value|0x898C
end_define

begin_comment
comment|/* 140 */
end_comment

begin_define
define|#
directive|define
name|SOME_FILES_AFFECTED_IN_USE
value|0x898D
end_define

begin_comment
comment|/* 141 */
end_comment

begin_define
define|#
directive|define
name|NO_FILES_AFFECTED_IN_USE
value|0x898E
end_define

begin_comment
comment|/* 142 */
end_comment

begin_define
define|#
directive|define
name|SOME_FILES_AFFECTED_READ_ONLY
value|0x898F
end_define

begin_comment
comment|/* 143 */
end_comment

begin_define
define|#
directive|define
name|NO_FILES_AFFECTED_READ_ONLY
value|0x8990
end_define

begin_comment
comment|/* 144 */
end_comment

begin_define
define|#
directive|define
name|SOME_FILES_RENAMED_NAME_EXISTS
value|0x8991
end_define

begin_comment
comment|/* 145 */
end_comment

begin_define
define|#
directive|define
name|NO_FILES_RENAMED_NAME_EXISTS
value|0x8992
end_define

begin_comment
comment|/* 146 */
end_comment

begin_define
define|#
directive|define
name|NO_READ_PRIVILEGES
value|0x8993
end_define

begin_comment
comment|/* 147 */
end_comment

begin_define
define|#
directive|define
name|NO_WRITE_PRIVILEGES_OR_READONLY
value|0x8994
end_define

begin_comment
comment|/* 148 */
end_comment

begin_define
define|#
directive|define
name|FILE_DETACHED
value|0x8995
end_define

begin_comment
comment|/* 149 */
end_comment

begin_define
define|#
directive|define
name|SERVER_OUT_OF_MEMORY
value|0x8996
end_define

begin_comment
comment|/* 150 */
end_comment

begin_define
define|#
directive|define
name|ERR_TARGET_NOT_A_SUBDIRECTORY
value|0x8996
end_define

begin_comment
comment|/* 150 can be changed later (note written by server people). */
end_comment

begin_define
define|#
directive|define
name|NO_DISK_SPACE_FOR_SPOOL_FILE
value|0x8997
end_define

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_NOT_ENABLED
value|0x8997
end_define

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|VOLUME_DOES_NOT_EXIST
value|0x8998
end_define

begin_comment
comment|/* 152 */
end_comment

begin_define
define|#
directive|define
name|DIRECTORY_FULL
value|0x8999
end_define

begin_comment
comment|/* 153 */
end_comment

begin_define
define|#
directive|define
name|RENAMING_ACROSS_VOLUMES
value|0x899A
end_define

begin_comment
comment|/* 154 */
end_comment

begin_define
define|#
directive|define
name|BAD_DIRECTORY_HANDLE
value|0x899B
end_define

begin_comment
comment|/* 155 */
end_comment

begin_define
define|#
directive|define
name|INVALID_PATH
value|0x899C
end_define

begin_comment
comment|/* 156 */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_TRUSTEES
value|0x899C
end_define

begin_comment
comment|/* 156 */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_DIRECTORY_HANDLES
value|0x899D
end_define

begin_comment
comment|/* 157 */
end_comment

begin_define
define|#
directive|define
name|INVALID_FILENAME
value|0x899E
end_define

begin_comment
comment|/* 158 */
end_comment

begin_define
define|#
directive|define
name|DIRECTORY_ACTIVE
value|0x899F
end_define

begin_comment
comment|/* 159 */
end_comment

begin_define
define|#
directive|define
name|DIRECTORY_NOT_EMPTY
value|0x89A0
end_define

begin_comment
comment|/* 160 */
end_comment

begin_define
define|#
directive|define
name|DIRECTORY_IO_ERROR
value|0x89A1
end_define

begin_comment
comment|/* 161 */
end_comment

begin_define
define|#
directive|define
name|READ_FILE_WITH_RECORD_LOCKED
value|0x89A2
end_define

begin_comment
comment|/* 162 */
end_comment

begin_define
define|#
directive|define
name|ERR_TRANSACTION_RESTARTED
value|0x89A3
end_define

begin_comment
comment|/* 163 */
end_comment

begin_define
define|#
directive|define
name|ERR_RENAME_DIR_INVALID
value|0x89A4
end_define

begin_comment
comment|/* 164 */
end_comment

begin_define
define|#
directive|define
name|ERR_INVALID_OPENCREATE_MODE
value|0x89A5
end_define

begin_comment
comment|/* 165 */
end_comment

begin_define
define|#
directive|define
name|ERR_ALREADY_IN_USE
value|0x89A6
end_define

begin_comment
comment|/* 166 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_ACTIVE
value|0x89A6
end_define

begin_comment
comment|/* 166 */
end_comment

begin_define
define|#
directive|define
name|ERR_INVALID_RESOURCE_TAG
value|0x89A7
end_define

begin_comment
comment|/* 167 */
end_comment

begin_define
define|#
directive|define
name|ERR_ACCESS_DENIED
value|0x89A8
end_define

begin_comment
comment|/* 168 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_NO_RIGHTS
value|0x89A8
end_define

begin_comment
comment|/* 168 */
end_comment

begin_define
define|#
directive|define
name|INVALID_DATA_STREAM
value|0x89BE
end_define

begin_comment
comment|/* 190 */
end_comment

begin_define
define|#
directive|define
name|INVALID_NAME_SPACE
value|0x89BF
end_define

begin_comment
comment|/* 191 */
end_comment

begin_define
define|#
directive|define
name|NO_ACCOUNTING_PRIVILEGES
value|0x89C0
end_define

begin_comment
comment|/* 192 */
end_comment

begin_define
define|#
directive|define
name|LOGIN_DENIED_NO_ACCOUNT_BALANCE
value|0x89C1
end_define

begin_comment
comment|/* 193 */
end_comment

begin_define
define|#
directive|define
name|LOGIN_DENIED_NO_CREDIT
value|0x89C2
end_define

begin_comment
comment|/* 194 */
end_comment

begin_define
define|#
directive|define
name|ERR_AUDITING_RECORD_SIZE
value|0x89C2
end_define

begin_comment
comment|/* 194 */
end_comment

begin_define
define|#
directive|define
name|ERR_TOO_MANY_HOLDS
value|0x89C3
end_define

begin_comment
comment|/* 195 */
end_comment

begin_define
define|#
directive|define
name|ACCOUNTING_DISABLED
value|0x89C4
end_define

begin_comment
comment|/* 196 */
end_comment

begin_define
define|#
directive|define
name|INTRUDER_DETECTION_LOCK
value|0x89C5
end_define

begin_comment
comment|/* 197 */
end_comment

begin_define
define|#
directive|define
name|NO_CONSOLE_OPERATOR
value|0x89C6
end_define

begin_comment
comment|/* 198 */
end_comment

begin_define
define|#
directive|define
name|NO_CONSOLE_PRIVILEGES
value|0x89C6
end_define

begin_comment
comment|/* 198 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_IO_FAILURE
value|0x89D0
end_define

begin_comment
comment|/* 208 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_QUEUE
value|0x89D1
end_define

begin_comment
comment|/* 209 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_Q_SERVER
value|0x89D2
end_define

begin_comment
comment|/* 210 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_Q_RIGHTS
value|0x89D3
end_define

begin_comment
comment|/* 211 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_FULL
value|0x89D4
end_define

begin_comment
comment|/* 212 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_Q_JOB
value|0x89D5
end_define

begin_comment
comment|/* 213 */
end_comment

begin_define
define|#
directive|define
name|ERR_NO_Q_JOB_RIGHTS
value|0x89D6
end_define

begin_comment
comment|/* 214 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_IN_SERVICE
value|0x89D7
end_define

begin_comment
comment|/* 215 */
end_comment

begin_define
define|#
directive|define
name|PASSWORD_NOT_UNIQUE
value|0x89D7
end_define

begin_comment
comment|/* 215 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_NOT_ACTIVE
value|0x89D8
end_define

begin_comment
comment|/* 216 */
end_comment

begin_define
define|#
directive|define
name|PASSWORD_TOO_SHORT
value|0x89D8
end_define

begin_comment
comment|/* 216 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_STN_NOT_SERVER
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|LOGIN_DENIED_NO_CONNECTION
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|ERR_MAXIMUM_LOGINS_EXCEEDED
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_HALTED
value|0x89DA
end_define

begin_comment
comment|/* 218 */
end_comment

begin_define
define|#
directive|define
name|UNAUTHORIZED_LOGIN_TIME
value|0x89DA
end_define

begin_comment
comment|/* 218 */
end_comment

begin_define
define|#
directive|define
name|UNAUTHORIZED_LOGIN_STATION
value|0x89DB
end_define

begin_comment
comment|/* 219 */
end_comment

begin_define
define|#
directive|define
name|ERR_Q_MAX_SERVERS
value|0x89DB
end_define

begin_comment
comment|/* 219 */
end_comment

begin_define
define|#
directive|define
name|ACCOUNT_DISABLED
value|0x89DC
end_define

begin_comment
comment|/* 220 */
end_comment

begin_define
define|#
directive|define
name|PASSWORD_HAS_EXPIRED_NO_GRACE
value|0x89DE
end_define

begin_comment
comment|/* 222 */
end_comment

begin_define
define|#
directive|define
name|PASSWORD_HAS_EXPIRED
value|0x89DF
end_define

begin_comment
comment|/* 223 */
end_comment

begin_define
define|#
directive|define
name|E_NO_MORE_USERS
value|0x89E7
end_define

begin_comment
comment|/* 231 */
end_comment

begin_define
define|#
directive|define
name|NOT_ITEM_PROPERTY
value|0x89E8
end_define

begin_comment
comment|/* 232 */
end_comment

begin_define
define|#
directive|define
name|WRITE_PROPERTY_TO_GROUP
value|0x89E8
end_define

begin_comment
comment|/* 232 */
end_comment

begin_define
define|#
directive|define
name|MEMBER_ALREADY_EXISTS
value|0x89E9
end_define

begin_comment
comment|/* 233 */
end_comment

begin_define
define|#
directive|define
name|NO_SUCH_MEMBER
value|0x89EA
end_define

begin_comment
comment|/* 234 */
end_comment

begin_define
define|#
directive|define
name|NOT_GROUP_PROPERTY
value|0x89EB
end_define

begin_comment
comment|/* 235 */
end_comment

begin_define
define|#
directive|define
name|NO_SUCH_SEGMENT
value|0x89EC
end_define

begin_comment
comment|/* 236 */
end_comment

begin_define
define|#
directive|define
name|PROPERTY_ALREADY_EXISTS
value|0x89ED
end_define

begin_comment
comment|/* 237 */
end_comment

begin_define
define|#
directive|define
name|OBJECT_ALREADY_EXISTS
value|0x89EE
end_define

begin_comment
comment|/* 238 */
end_comment

begin_define
define|#
directive|define
name|INVALID_NAME
value|0x89EF
end_define

begin_comment
comment|/* 239 */
end_comment

begin_define
define|#
directive|define
name|WILD_CARD_NOT_ALLOWED
value|0x89F0
end_define

begin_comment
comment|/* 240 */
end_comment

begin_define
define|#
directive|define
name|INVALID_BINDERY_SECURITY
value|0x89F1
end_define

begin_comment
comment|/* 241 */
end_comment

begin_define
define|#
directive|define
name|NO_OBJECT_READ_PRIVILEGE
value|0x89F2
end_define

begin_comment
comment|/* 242 */
end_comment

begin_define
define|#
directive|define
name|NO_OBJECT_RENAME_PRIVILEGE
value|0x89F3
end_define

begin_comment
comment|/* 243 */
end_comment

begin_define
define|#
directive|define
name|NO_OBJECT_DELETE_PRIVILEGE
value|0x89F4
end_define

begin_comment
comment|/* 244 */
end_comment

begin_define
define|#
directive|define
name|NO_OBJECT_CREATE_PRIVILEGE
value|0x89F5
end_define

begin_comment
comment|/* 245 */
end_comment

begin_define
define|#
directive|define
name|NO_PROPERTY_DELETE_PRIVILEGE
value|0x89F6
end_define

begin_comment
comment|/* 246 */
end_comment

begin_define
define|#
directive|define
name|NO_PROPERTY_CREATE_PRIVILEGE
value|0x89F7
end_define

begin_comment
comment|/* 247 */
end_comment

begin_define
define|#
directive|define
name|NO_PROPERTY_WRITE_PRIVILEGE
value|0x89F8
end_define

begin_comment
comment|/* 248 */
end_comment

begin_define
define|#
directive|define
name|NO_FREE_CONNECTION_SLOTS
value|0x89F9
end_define

begin_comment
comment|/* 249 */
end_comment

begin_define
define|#
directive|define
name|NO_PROPERTY_READ_PRIVILEGE
value|0x89F9
end_define

begin_comment
comment|/* 249 */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_SERVER_SLOTS
value|0x89FA
end_define

begin_comment
comment|/* 250 */
end_comment

begin_define
define|#
directive|define
name|TEMP_REMAP_ERROR
value|0x89FA
end_define

begin_comment
comment|/* 250 */
end_comment

begin_define
define|#
directive|define
name|INVALID_PARAMETERS
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|NO_SUCH_PROPERTY
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|ERR_NCP_NOT_SUPPORTED
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|INTERNET_PACKET_REQT_CANCELED
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_FILE_SERVER
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|MESSAGE_QUEUE_FULL
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|NO_SUCH_OBJECT
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|LOCK_COLLISION
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|BAD_STATION_NUMBER
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|INVALID_PACKET_LENGTH
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_REQUEST
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|BINDERY_LOCKED
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|TRUSTEE_NOT_FOUND
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|DIRECTORY_LOCKED
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|INVALID_SEMAPHORE_NAME_LENGTH
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|PACKET_NOT_DELIVERABLE
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|SERVER_BINDERY_LOCKED
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|SOCKET_TABLE_FULL
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|SPOOL_DIRECTORY_ERROR
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|SUPERVISOR_HAS_DISABLED_LOGIN
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT_FAILURE
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|BAD_PRINTER_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|BAD_RECORD_OFFSET
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|CLOSE_FCB_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|FILE_EXTENSION_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|FILE_NAME_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|HARDWARE_FAILURE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|INVALID_DRIVE_NUMBER
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|DOS_INVALID_DRIVE
value|0x000F
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|INVALID_INITIAL_SEMAPHORE_VALUE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|INVALID_SEMAPHORE_HANDLE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|IO_BOUND_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NO_FILES_FOUND_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NO_RESPONSE_FROM_SERVER
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NO_SUCH_OBJECT_OR_BAD_PASSWORD
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|PATH_NOT_LOCATABLE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|QUEUE_FULL_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|REQUEST_NOT_OUTSTANDING
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKET_ALREADY_OPEN
end_ifndef

begin_define
define|#
directive|define
name|SOCKET_ALREADY_OPEN
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCK_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FAILURE
end_ifndef

begin_define
define|#
directive|define
name|FAILURE
value|0x89FF
end_define

begin_comment
comment|/* 255 Generic Failure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define NOT_SAME_LOCAL_DRIVE         0x89F6 */
end_comment

begin_comment
comment|/* #define TARGET_DRIVE_NOT_LOCAL       0x89F7 */
end_comment

begin_comment
comment|/* #define ALREADY_ATTACHED_TO_SERVER   0x89F8 */
end_comment

begin_comment
comment|/* 248 */
end_comment

begin_comment
comment|/* #define NOT_ATTACHED_TO_SERVER       0x89F8 */
end_comment

begin_comment
comment|/**** Network errors ****/
end_comment

begin_comment
comment|/* Decimal values at end of line are 32768 lower than actual */
end_comment

begin_define
define|#
directive|define
name|NWE_ALREADY_ATTACHED
value|0x8800
end_define

begin_comment
comment|/* 0  - Attach attempted to server with valid, existing connection */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_INVALID
value|0x8801
end_define

begin_comment
comment|/* 1  - Request attempted with invalid or non-attached connection handle */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_IN_USE
value|0x8802
end_define

begin_comment
comment|/* 2  - OS/2 only (NOT USED) */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_CANNOT_MAP
value|0x8803
end_define

begin_comment
comment|/* 3  - Map drive attempted but unable to add new current directory structure */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_BAD_PATH
value|0x8804
end_define

begin_comment
comment|/* 4  - Map drive attempted with invalid path specification */
end_comment

begin_define
define|#
directive|define
name|NWE_NET_RECEIVE
value|0x8805
end_define

begin_comment
comment|/* 5  - Attempt to receive from the selected transport failed */
end_comment

begin_define
define|#
directive|define
name|NWE_NET_UNKNOWN
value|0x8806
end_define

begin_comment
comment|/* 6  - Network send attempted with an un-specific network error */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_BAD_SLOT
value|0x8807
end_define

begin_comment
comment|/* 7  - Server request attempted with invalid server connection slot */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_NO_SLOTS
value|0x8808
end_define

begin_comment
comment|/* 8  - Attach attempted to server with no connection slots available */
end_comment

begin_define
define|#
directive|define
name|NWE_NET_SEND
value|0x8809
end_define

begin_comment
comment|/* 9  - Attempt to send on the selected transport failed */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_NO_ROUTE
value|0x880A
end_define

begin_comment
comment|/* 10 - Attempted to find route to server where no route exists */
end_comment

begin_define
define|#
directive|define
name|NWE_BAD_LOCAL_TARGET
value|0x880B
end_define

begin_comment
comment|/* 11 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_REQ_TOO_MANY_REQ_FRAGS
value|0x880C
end_define

begin_comment
comment|/* 12 - Attempted request with too many request fragments specified */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_LIST_OVERFLOW
value|0x880D
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|NWE_BUFFER_OVERFLOW
value|0x880E
end_define

begin_comment
comment|/* 14 - Attempt to receive more data than the reply buffer had room for */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_NO_CONN
value|0x880F
end_define

begin_comment
comment|/* 15 - Attempt to get connection for a server not connected */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_ROUTER_FOUND
value|0x8810
end_define

begin_comment
comment|/* 16 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_FUNCTION_INVALID
value|0x8811
end_define

begin_comment
comment|/* 17 - Attempted function call to non- existent or illegal function */
end_comment

begin_define
define|#
directive|define
name|NWE_SCAN_COMPLETE
value|0x8812
end_define

begin_define
define|#
directive|define
name|NWE_UNSUPPORTED_NAME_FORMAT_TYP
value|0x8813
end_define

begin_define
define|#
directive|define
name|NWE_HANDLE_ALREADY_LICENSED
value|0x8814
end_define

begin_define
define|#
directive|define
name|NWE_HANDLE_ALREADY_UNLICENSED
value|0x8815
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_NCP_PACKET_LENGTH
value|0x8816
end_define

begin_define
define|#
directive|define
name|NWE_SETTING_UP_TIMEOUT
value|0x8817
end_define

begin_define
define|#
directive|define
name|NWE_SETTING_SIGNALS
value|0x8818
end_define

begin_define
define|#
directive|define
name|NWE_SERVER_CONNECTION_LOST
value|0x8819
end_define

begin_define
define|#
directive|define
name|NWE_OUT_OF_HEAP_SPACE
value|0x881A
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_SERVICE_REQUEST
value|0x881B
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_TASK_NUMBER
value|0x881C
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_MESSAGE_LENGTH
value|0x881D
end_define

begin_define
define|#
directive|define
name|NWE_EA_SCAN_DONE
value|0x881E
end_define

begin_define
define|#
directive|define
name|NWE_BAD_CONNECTION_NUMBER
value|0x881F
end_define

begin_define
define|#
directive|define
name|NWE_MULT_TREES_NOT_SUPPORTED
value|0x8820
end_define

begin_comment
comment|/* 32 - Attempt to open a connection to a DS tree other than the default tree */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_NOT_SAME
value|0x8830
end_define

begin_comment
comment|/* 48 - Internal server request attempted across different server connections */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_PRIMARY_NOT_SET
value|0x8831
end_define

begin_comment
comment|/* 49 - Attempt to retrieve default connection with no primary connection set */
end_comment

begin_define
define|#
directive|define
name|NWE_PRN_CAPTURE_NOT_IN_PROGRESS
value|0x8832
end_define

begin_comment
comment|/* 50 - Capture information requested on port with no capture in progress */
end_comment

begin_define
define|#
directive|define
name|NWE_BUFFER_INVALID_LEN
value|0x8833
end_define

begin_comment
comment|/* 51 - Used to indicate length which caller requested on a GetDNC or SetDNC was too large */
end_comment

begin_define
define|#
directive|define
name|NWE_USER_NO_NAME
value|0x8834
end_define

begin_comment
comment|/* 52 */
end_comment

begin_define
define|#
directive|define
name|NWE_PRN_NO_LOCAL_SPOOLER
value|0x8835
end_define

begin_comment
comment|/* 53 - Capture requested without having the local print spooler installed */
end_comment

begin_define
define|#
directive|define
name|NWE_PARAM_INVALID
value|0x8836
end_define

begin_comment
comment|/* 54 - Attempted function with an invalid function parameter specified */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_OPEN_FAILED
value|0x8837
end_define

begin_comment
comment|/* 55 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_NO_FILE
value|0x8838
end_define

begin_comment
comment|/* 56 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_READ_FAILED
value|0x8839
end_define

begin_comment
comment|/* 57 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_LINE_TOO_LONG
value|0x883A
end_define

begin_comment
comment|/* 58 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_LINES_IGNORED
value|0x883B
end_define

begin_comment
comment|/* 59 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_RESOURCE_NOT_OWNED
value|0x883C
end_define

begin_comment
comment|/* 60 - Attempted request made with a parameter using foriegn resource */
end_comment

begin_define
define|#
directive|define
name|NWE_DAEMON_INSTALLED
value|0x883D
end_define

begin_comment
comment|/* 61 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_PRN_SPOOLER_INSTALLED
value|0x883E
end_define

begin_comment
comment|/* 62 - Attempted load of print spooler with print spooler already installed */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_TABLE_FULL
value|0x883F
end_define

begin_comment
comment|/* 63 - Attempted to allocate a connection handle with no more local connection table entries */
end_comment

begin_define
define|#
directive|define
name|NWE_CFG_SECTION_NOT_FOUND
value|0x8840
end_define

begin_comment
comment|/* 64 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_TRAN_INVALID_TYPE
value|0x8841
end_define

begin_comment
comment|/* 65 - Attempted function on a connection with an invalid transport selected */
end_comment

begin_define
define|#
directive|define
name|NWE_TDS_TAG_IN_USE
value|0x8842
end_define

begin_comment
comment|/* 66 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_TDS_OUT_OF_MEMORY
value|0x8843
end_define

begin_comment
comment|/* 67 - OS/2 only */
end_comment

begin_define
define|#
directive|define
name|NWE_TDS_INVALID_TAG
value|0x8844
end_define

begin_comment
comment|/* 68 - Attempted TDS function with invalid tag */
end_comment

begin_define
define|#
directive|define
name|NWE_TDS_WRITE_TRUNCATED
value|0x8845
end_define

begin_comment
comment|/* 69 - Attempted TDS write with buffer that exceeded buffer */
end_comment

begin_define
define|#
directive|define
name|NWE_DS_NO_CONN
value|0x8846
end_define

begin_comment
comment|/* 70 */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVICE_BUSY
value|0x8846
end_define

begin_comment
comment|/* 70 - Attempted request made to partially asynchronous function in busy state */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_NOT_FOUND
value|0x8847
end_define

begin_comment
comment|/* 71 - Attempted connect failed to find any servers responding */
end_comment

begin_define
define|#
directive|define
name|NWE_VLM_INVALID
value|0x8848
end_define

begin_comment
comment|/* 72 - Attempted function call to non-existant or not-loaded overlay */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_ALREADY_MAPPED
value|0x8849
end_define

begin_comment
comment|/* 73 - Attempted map to network drive that was already mapped */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_LOCAL_IN_USE
value|0x884A
end_define

begin_comment
comment|/* 74 - Attempted map to local drive that was in use */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_NONE_AVAILABLE
value|0x884B
end_define

begin_comment
comment|/* 75 - Attempted map to next available drive when none were available */
end_comment

begin_define
define|#
directive|define
name|NWE_DEVICE_NOT_REDIRECTED
value|0x884C
end_define

begin_comment
comment|/* 76 - The device is not redirected */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_MAX_REACHED
value|0x884D
end_define

begin_comment
comment|/* 77 - Maximum number of files was reached */
end_comment

begin_define
define|#
directive|define
name|NWE_UNLOAD_FAILED
value|0x884E
end_define

begin_comment
comment|/* 78 - Attempted unload failed */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_IN_USE
value|0x884F
end_define

begin_comment
comment|/* 79 - Attempted re-use of already in use connection entry */
end_comment

begin_define
define|#
directive|define
name|NWE_REQ_TOO_MANY_REP_FRAGS
value|0x8850
end_define

begin_comment
comment|/* 80 - Attempted request with too many reply fragments specified */
end_comment

begin_define
define|#
directive|define
name|NWE_NAME_TABLE_FULL
value|0x8851
end_define

begin_comment
comment|/* 81 - Attempted to add a name into the name table after it was full */
end_comment

begin_define
define|#
directive|define
name|NWE_SOCKET_NOT_OPEN
value|0x8852
end_define

begin_comment
comment|/* 82 - Listen was posted on unopened socket */
end_comment

begin_define
define|#
directive|define
name|NWE_MEMORY_MGR_ERROR
value|0x8853
end_define

begin_comment
comment|/* 83 - Attempted enhanced memory operation failed */
end_comment

begin_define
define|#
directive|define
name|NWE_SFT3_ERROR
value|0x8854
end_define

begin_comment
comment|/* 84 - An SFT3 switch occured mid-transfer */
end_comment

begin_define
define|#
directive|define
name|NWE_DS_PREFERRED_NOT_FOUND
value|0x8855
end_define

begin_comment
comment|/* 85 - the preferred directory server was not established but another directory server was returned */
end_comment

begin_define
define|#
directive|define
name|NWE_DEVICE_NOT_RECOGNIZED
value|0x8856
end_define

begin_comment
comment|/* 86 - used to determine if the device is not used by VISE so pass it on to the next redirector, if any. */
end_comment

begin_define
define|#
directive|define
name|NWE_NET_INVALID_TYPE
value|0x8857
end_define

begin_comment
comment|/* 87 - the network type (Bind/NDS) does not match the server version */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_OPEN_FAILED
value|0x8858
end_define

begin_comment
comment|/* 88 - generic open failure error, invalid path, access denied, etc.. */
end_comment

begin_define
define|#
directive|define
name|NWE_DS_PREFERRED_NOT_SPECIFIED
value|0x8859
end_define

begin_comment
comment|/* 89 - no preferred name specified */
end_comment

begin_define
define|#
directive|define
name|NWE_SOCKET_OPEN_FAILED
value|0x885A
end_define

begin_comment
comment|/* 90 - error opening a socket */
end_comment

begin_define
define|#
directive|define
name|NWE_SIGNATURE_LEVEL_CONFLICT
value|0x8861
end_define

begin_define
define|#
directive|define
name|NWE_NO_LOCK_FOUND
value|0x8862
end_define

begin_comment
comment|/* OS/2 - process lock on conn handle failed, process ID not recognized */
end_comment

begin_define
define|#
directive|define
name|NWE_LOCK_TABLE_FULL
value|0x8863
end_define

begin_comment
comment|/* OS/2 - process lock on conn handle failed, process lock table full */
end_comment

begin_define
define|#
directive|define
name|NWE_INVALID_MATCH_DATA
value|0x8864
end_define

begin_define
define|#
directive|define
name|NWE_MATCH_FAILED
value|0x8865
end_define

begin_define
define|#
directive|define
name|NWE_NO_MORE_ENTRIES
value|0x8866
end_define

begin_define
define|#
directive|define
name|NWE_INSUFFICIENT_RESOURCES
value|0x8867
end_define

begin_define
define|#
directive|define
name|NWE_STRING_TRANSLATION
value|0x8868
end_define

begin_define
define|#
directive|define
name|NWE_ACCESS_VIOLATION
value|0x8869
end_define

begin_define
define|#
directive|define
name|NWE_NOT_AUTHENTICATED
value|0x886A
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_LEVEL
value|0x886B
end_define

begin_define
define|#
directive|define
name|NWE_RESOURCE_LOCK
value|0x886C
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_NAME_FORMAT
value|0x886D
end_define

begin_define
define|#
directive|define
name|NWE_OBJECT_EXISTS
value|0x886E
end_define

begin_define
define|#
directive|define
name|NWE_OBJECT_NOT_FOUND
value|0x886F
end_define

begin_define
define|#
directive|define
name|NWE_UNSUPPORTED_TRAN_TYPE
value|0x8870
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_STRING_TYPE
value|0x8871
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_OWNER
value|0x8872
end_define

begin_define
define|#
directive|define
name|NWE_UNSUPPORTED_AUTHENTICATOR
value|0x8873
end_define

begin_define
define|#
directive|define
name|NWE_IO_PENDING
value|0x8874
end_define

begin_define
define|#
directive|define
name|NWE_INVALID_DRIVE_NUMBER
value|0x8875
end_define

begin_define
define|#
directive|define
name|NWE_REPLY_TRUNCATED
value|0x88e6
end_define

begin_comment
comment|/* 230 NLM */
end_comment

begin_define
define|#
directive|define
name|NWE_REQUESTER_FAILURE
value|0x88FF
end_define

begin_comment
comment|/* Server Errors */
end_comment

begin_define
define|#
directive|define
name|NWE_INSUFFICIENT_SPACE
value|0x8901
end_define

begin_comment
comment|/* 001 */
end_comment

begin_define
define|#
directive|define
name|NWE_BUFFER_TOO_SMALL
value|0x8977
end_define

begin_comment
comment|/* 119 */
end_comment

begin_define
define|#
directive|define
name|NWE_VOL_FLAG_NOT_SET
value|0x8978
end_define

begin_comment
comment|/* 120 the service requested, not avail. on the selected vol. */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_ITEMS_FOUND
value|0x8979
end_define

begin_comment
comment|/* 121 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_ALREADY_TEMP
value|0x897a
end_define

begin_comment
comment|/* 122 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_ALREADY_LOGGED_IN
value|0x897b
end_define

begin_comment
comment|/* 123 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_NOT_AUTHENTICATED
value|0x897c
end_define

begin_comment
comment|/* 124 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_NOT_LOGGED_IN
value|0x897d
end_define

begin_comment
comment|/* 125 */
end_comment

begin_define
define|#
directive|define
name|NWE_NCP_BOUNDARY_CHECK_FAILED
value|0x897e
end_define

begin_comment
comment|/* 126 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOCK_WAITING
value|0x897f
end_define

begin_comment
comment|/* 127 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOCK_FAIL
value|0x8980
end_define

begin_comment
comment|/* 128 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_IN_USE
value|0x8980
end_define

begin_comment
comment|/* 128 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_HANDLES
value|0x8981
end_define

begin_comment
comment|/* 129 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_OPEN_PRIV
value|0x8982
end_define

begin_comment
comment|/* 130 */
end_comment

begin_define
define|#
directive|define
name|NWE_DISK_IO_ERROR
value|0x8983
end_define

begin_comment
comment|/* 131 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_HARD_IO_ERROR
value|0x8983
end_define

begin_comment
comment|/* 131 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_CREATE_PRIV
value|0x8984
end_define

begin_comment
comment|/* 132 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_NOT_SUPV
value|0x8984
end_define

begin_comment
comment|/* 132 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_CREATE_DEL_PRIV
value|0x8985
end_define

begin_comment
comment|/* 133 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_EXISTS_READ_ONLY
value|0x8986
end_define

begin_comment
comment|/* 134 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_WILD_CARDS_IN_NAME
value|0x8987
end_define

begin_comment
comment|/* 135 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_INVALID_HANDLE
value|0x8988
end_define

begin_comment
comment|/* 136 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_SRCH_PRIV
value|0x8989
end_define

begin_comment
comment|/* 137 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_DEL_PRIV
value|0x898A
end_define

begin_comment
comment|/* 138 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_RENAME_PRIV
value|0x898B
end_define

begin_comment
comment|/* 139 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_MOD_PRIV
value|0x898C
end_define

begin_comment
comment|/* 140 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_SOME_IN_USE
value|0x898D
end_define

begin_comment
comment|/* 141 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NONE_IN_USE
value|0x898E
end_define

begin_comment
comment|/* 142 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_SOME_READ_ONLY
value|0x898F
end_define

begin_comment
comment|/* 143 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NONE_READ_ONLY
value|0x8990
end_define

begin_comment
comment|/* 144 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_SOME_RENAMED_EXIST
value|0x8991
end_define

begin_comment
comment|/* 145 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NONE_RENAMED_EXIST
value|0x8992
end_define

begin_comment
comment|/* 146 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_READ_PRIV
value|0x8993
end_define

begin_comment
comment|/* 147 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NO_WRITE_PRIV
value|0x8994
end_define

begin_comment
comment|/* 148 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_READ_ONLY
value|0x8994
end_define

begin_comment
comment|/* 148 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_DETACHED
value|0x8995
end_define

begin_comment
comment|/* 149 */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_OUT_OF_MEMORY
value|0x8996
end_define

begin_comment
comment|/* 150 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_TARGET_INVALID
value|0x8996
end_define

begin_comment
comment|/* 150 */
end_comment

begin_define
define|#
directive|define
name|NWE_DISK_NO_SPOOL_SPACE
value|0x8997
end_define

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_NOT_ENABLED
value|0x8997
end_define

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|NWE_VOL_INVALID
value|0x8998
end_define

begin_comment
comment|/* 152 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_FULL
value|0x8999
end_define

begin_comment
comment|/* 153 */
end_comment

begin_define
define|#
directive|define
name|NWE_VOL_RENAMING_ACROSS
value|0x899A
end_define

begin_comment
comment|/* 154 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIRHANDLE_INVALID
value|0x899B
end_define

begin_comment
comment|/* 155 */
end_comment

begin_define
define|#
directive|define
name|NWE_PATH_INVALID
value|0x899C
end_define

begin_comment
comment|/* 156 */
end_comment

begin_define
define|#
directive|define
name|NWE_TRUSTEES_NO_MORE
value|0x899C
end_define

begin_comment
comment|/* 156 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIRHANDLE_NO_MORE
value|0x899D
end_define

begin_comment
comment|/* 157 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NAME_INVALID
value|0x899E
end_define

begin_comment
comment|/* 158 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_ACTIVE
value|0x899F
end_define

begin_comment
comment|/* 159 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_NOT_EMPTY
value|0x89A0
end_define

begin_comment
comment|/* 160 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_IO_ERROR
value|0x89A1
end_define

begin_comment
comment|/* 161 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_IO_LOCKED
value|0x89A2
end_define

begin_comment
comment|/* 162 */
end_comment

begin_define
define|#
directive|define
name|NWE_TTS_RANSACTION_RESTARTED
value|0x89A3
end_define

begin_comment
comment|/* 163 */
end_comment

begin_define
define|#
directive|define
name|NWE_TTS_TRANSACTION_RESTARTED
value|0x89A3
end_define

begin_comment
comment|/* 163 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_RENAME_INVALID
value|0x89A4
end_define

begin_comment
comment|/* 164 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_OPENCREAT_MODE_INVALID
value|0x89A5
end_define

begin_comment
comment|/* 165 */
end_comment

begin_define
define|#
directive|define
name|NWE_ALREADY_IN_USE
value|0x89A6
end_define

begin_comment
comment|/* 166 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_ACTIVE
value|0x89A6
end_define

begin_comment
comment|/* 166 */
end_comment

begin_define
define|#
directive|define
name|NWE_RESOURCE_TAG_INVALID
value|0x89A7
end_define

begin_comment
comment|/* 167 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCESS_DENIED
value|0x89A8
end_define

begin_comment
comment|/* 168 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_NO_RIGHTS
value|0x89A8
end_define

begin_comment
comment|/* 168 */
end_comment

begin_define
define|#
directive|define
name|NWE_DATA_STREAM_INVALID
value|0x89BE
end_define

begin_comment
comment|/* 190 */
end_comment

begin_define
define|#
directive|define
name|NWE_NAME_SPACE_INVALID
value|0x89BF
end_define

begin_comment
comment|/* 191 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCTING_NO_PRIV
value|0x89C0
end_define

begin_comment
comment|/* 192 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCTING_NO_BALANCE
value|0x89C1
end_define

begin_comment
comment|/* 193 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCTING_NO_CREDIT
value|0x89C2
end_define

begin_comment
comment|/* 194 */
end_comment

begin_define
define|#
directive|define
name|NWE_AUDITING_RECORD_SIZE
value|0x89C2
end_define

begin_comment
comment|/* 194 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCTING_TOO_MANY_HOLDS
value|0x89C3
end_define

begin_comment
comment|/* 195 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCTING_DISABLED
value|0x89C4
end_define

begin_comment
comment|/* 196 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_LOCKOUT
value|0x89C5
end_define

begin_comment
comment|/* 197 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONSOLE_NO_PRIV
value|0x89C6
end_define

begin_comment
comment|/* 198 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_IO_FAILURE
value|0x89D0
end_define

begin_comment
comment|/* 208 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NONE
value|0x89D1
end_define

begin_comment
comment|/* 209 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NO_SERVER
value|0x89D2
end_define

begin_comment
comment|/* 210 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NO_RIGHTS
value|0x89D3
end_define

begin_comment
comment|/* 211 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_FULL
value|0x89D4
end_define

begin_comment
comment|/* 212 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NO_JOB
value|0x89D5
end_define

begin_comment
comment|/* 213 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NO_JOB_RIGHTS
value|0x89D6
end_define

begin_comment
comment|/* 214 */
end_comment

begin_define
define|#
directive|define
name|NWE_PASSWORD_UNENCRYPTED
value|0x89D6
end_define

begin_comment
comment|/* 214 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_IN_SERVICE
value|0x89D7
end_define

begin_comment
comment|/* 215 */
end_comment

begin_define
define|#
directive|define
name|NWE_PASSWORD_NOT_UNIQUE
value|0x89D7
end_define

begin_comment
comment|/* 215 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_NOT_ACTIVE
value|0x89D8
end_define

begin_comment
comment|/* 216 */
end_comment

begin_define
define|#
directive|define
name|NWE_PASSWORD_TOO_SHORT
value|0x89D8
end_define

begin_comment
comment|/* 216 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_STN_NOT_SERVER
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_NO_CONN
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_MAX_EXCEEDED
value|0x89D9
end_define

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_HALTED
value|0x89DA
end_define

begin_comment
comment|/* 218 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_UNAUTHORIZED_TIME
value|0x89DA
end_define

begin_comment
comment|/* 218 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_UNAUTHORIZED_STATION
value|0x89DB
end_define

begin_comment
comment|/* 219 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_MAX_SERVERS
value|0x89DB
end_define

begin_comment
comment|/* 219 */
end_comment

begin_define
define|#
directive|define
name|NWE_ACCT_DISABLED
value|0x89DC
end_define

begin_comment
comment|/* 220 */
end_comment

begin_define
define|#
directive|define
name|NWE_PASSWORD_INVALID
value|0x89DE
end_define

begin_comment
comment|/* 222 */
end_comment

begin_define
define|#
directive|define
name|NWE_PASSWORD_EXPIRED
value|0x89DF
end_define

begin_comment
comment|/* 223 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_NO_CONN_AVAIL
value|0x89E0
end_define

begin_comment
comment|/* 224 */
end_comment

begin_define
define|#
directive|define
name|NWE_E_NO_MORE_USERS
value|0x89E7
end_define

begin_comment
comment|/* 231 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NOT_ITEM_PROP
value|0x89E8
end_define

begin_comment
comment|/* 232 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_WRITE_TO_GROUP_PROP
value|0x89E8
end_define

begin_comment
comment|/* 232 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_MEMBER_ALREADY_EXISTS
value|0x89E9
end_define

begin_comment
comment|/* 233 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NO_SUCH_MEMBER
value|0x89EA
end_define

begin_comment
comment|/* 234 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NOT_GROUP_PROP
value|0x89EB
end_define

begin_comment
comment|/* 235 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NO_SUCH_SEGMENT
value|0x89EC
end_define

begin_comment
comment|/* 236 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_PROP_ALREADY_EXISTS
value|0x89ED
end_define

begin_comment
comment|/* 237 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_OBJ_ALREADY_EXISTS
value|0x89EE
end_define

begin_comment
comment|/* 238 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NAME_INVALID
value|0x89EF
end_define

begin_comment
comment|/* 239 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_WILDCARD_INVALID
value|0x89F0
end_define

begin_comment
comment|/* 240 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_SECURITY_INVALID
value|0x89F1
end_define

begin_comment
comment|/* 241 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_OBJ_NO_READ_PRIV
value|0x89F2
end_define

begin_comment
comment|/* 242 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_OBJ_NO_RENAME_PRIV
value|0x89F3
end_define

begin_comment
comment|/* 243 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_OBJ_NO_DELETE_PRIV
value|0x89F4
end_define

begin_comment
comment|/* 244 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_OBJ_NO_CREATE_PRIV
value|0x89F5
end_define

begin_comment
comment|/* 245 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_PROP_NO_DELETE_PRIV
value|0x89F6
end_define

begin_comment
comment|/* 246 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_PROP_NO_CREATE_PRIV
value|0x89F7
end_define

begin_comment
comment|/* 247 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_PROP_NO_WRITE_PRIV
value|0x89F8
end_define

begin_comment
comment|/* 248 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_PROP_NO_READ_PRIV
value|0x89F9
end_define

begin_comment
comment|/* 249 */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_FREE_CONN_SLOTS
value|0x89F9
end_define

begin_comment
comment|/* 249 */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_MORE_SERVER_SLOTS
value|0x89FA
end_define

begin_comment
comment|/* 250 */
end_comment

begin_define
define|#
directive|define
name|NWE_TEMP_REMAP_ERROR
value|0x89FA
end_define

begin_comment
comment|/* 250 */
end_comment

begin_define
define|#
directive|define
name|NWE_PARAMETERS_INVALID
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NO_SUCH_PROP
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|NWE_NCP_NOT_SUPPORTED
value|0x89FB
end_define

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|NWE_INET_PACKET_REQ_CANCELED
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|NWE_SERVER_UNKNOWN
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|NWE_MSG_Q_FULL
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_NO_SUCH_OBJ
value|0x89FC
end_define

begin_comment
comment|/* 252 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOCK_COLLISION
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|NWE_CONN_NUM_INVALID
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|NWE_PACKET_LEN_INVALID
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|NWE_UNKNOWN_REQ
value|0x89FD
end_define

begin_comment
comment|/* 253 */
end_comment

begin_define
define|#
directive|define
name|NWE_BIND_LOCKED
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_TRUSTEE_NOT_FOUND
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_DIR_LOCKED
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_SEM_INVALID_NAME_LEN
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_PACKET_NOT_DELIVERABLE
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_SOCKET_TABLE_FULL
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_SPOOL_DIR_ERROR
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOGIN_DISABLED_BY_SUPER
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_TIMEOUT_FAILURE
value|0x89FE
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_EXT
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_FILE_NAME
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_HARD_FAILURE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_FCB_CLOSE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_IO_BOUND
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_BAD_SPOOL_PRINTER
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_BAD_RECORD_OFFSET
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_DRIVE_INVALID_NUM
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_SEM_INVALID_INIT_VAL
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_SEM_INVALID_HANDLE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_FILES_FOUND_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_RESPONSE_FROM_SERVER
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_NO_OBJ_OR_BAD_PASSWORD
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_PATH_NOT_LOCATABLE
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_Q_FULL_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_REQ_NOT_OUTSTANDING
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_SOCKET_ALREADY_OPEN
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_LOCK_ERROR
value|0x89FF
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|NWE_FAILURE
value|0x89FF
end_define

begin_comment
comment|/* 255 Generic Failure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NWERROR_H_ */
end_comment

end_unit

