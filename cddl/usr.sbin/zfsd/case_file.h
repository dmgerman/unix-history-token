begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file case_file.h  *  * CaseFile objects aggregate vdev faults that may require ZFSD action  * in order to maintain the health of a ZFS pool.  *  * Header requirements:  *  *    #include<list>  *  *    #include "callout.h"  *    #include "zfsd_event.h"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CASE_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CASE_FILE_H_
end_define

begin_comment
comment|/*=========================== Forward Declarations ===========================*/
end_comment

begin_decl_stmt
name|class
name|CaseFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Vdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*------------------------------- CaseFileList -------------------------------*/
end_comment

begin_comment
comment|/**  * CaseFileList is a specialization of the standard list STL container.  */
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|list
operator|<
name|CaseFile
operator|*
operator|>
name|CaseFileList
expr_stmt|;
end_typedef

begin_comment
comment|/*--------------------------------- CaseFile ---------------------------------*/
end_comment

begin_comment
comment|/**  * A CaseFile object is instantiated anytime a vdev for an active pool  * experiences an I/O error, is faulted by ZFS, or is determined to be  * missing/removed.  *  * A vdev may have at most one CaseFile.  *  * CaseFiles are retired when a vdev leaves an active pool configuration  * or an action is taken to resolve the issues recorded in the CaseFile.  *  * Logging a case against a vdev does not imply that an immediate action  * to resolve a fault is required or even desired.  For example, a CaseFile  * must accumulate a number of I/O errors in order to flag a device as  * degraded.  *  * Vdev I/O errors are not recorded in ZFS label inforamation.  For this  * reasons, CaseFile%%s with accumulated I/O error events are serialized  * to the file system so that they survive across boots.  Currently all  * other fault types can be reconstructed from ZFS label information, so  * CaseFile%%s for missing, faulted, or degradded members are just recreated  * at ZFSD startup instead of being deserialized from the file system.  */
end_comment

begin_decl_stmt
name|class
name|CaseFile
block|{
name|public
label|:
comment|/** 	 * \brief Find a CaseFile object by a vdev's pool/vdev GUID tuple. 	 * 	 * \param poolGUID  Pool GUID for the vdev of the CaseFile to find. 	 * 		    If InvalidGuid, then only match the vdev GUID 	 * 		    instead of both pool and vdev GUIDs. 	 * \param vdevGUID  Vdev GUID for the vdev of the CaseFile to find. 	 * 	 * \return  If found, a pointer to a valid CaseFile object. 	 *          Otherwise NULL. 	 */
specifier|static
name|CaseFile
modifier|*
name|Find
argument_list|(
name|DevdCtl
operator|::
name|Guid
name|poolGUID
argument_list|,
name|DevdCtl
operator|::
name|Guid
name|vdevGUID
argument_list|)
decl_stmt|;
comment|/** 	 * \brief Find a CaseFile object by a vdev's current/last known 	 *        physical path. 	 * 	 * \param physPath  Physical path of the vdev of the CaseFile to find. 	 * 	 * \return  If found, a pointer to a valid CaseFile object. 	 *          Otherwise NULL. 	 */
specifier|static
name|CaseFile
modifier|*
name|Find
parameter_list|(
specifier|const
name|string
modifier|&
name|physPath
parameter_list|)
function_decl|;
comment|/** 	 * \brief ReEvaluate all open cases whose pool guid matches the argument 	 * 	 * \param poolGUID	Only reevaluate cases for this pool 	 * \param event		Try to consume this event with the casefile 	 */
specifier|static
name|void
name|ReEvaluateByGuid
argument_list|(
name|DevdCtl
operator|::
name|Guid
name|poolGUID
argument_list|,
specifier|const
name|ZfsEvent
operator|&
name|event
argument_list|)
decl_stmt|;
comment|/** 	 * \brief Create or return an existing active CaseFile for the 	 *        specified vdev. 	 * 	 * \param vdev  The vdev object for which to find/create a CaseFile. 	 * 	 * \return  A reference to a valid CaseFile object. 	 */
specifier|static
name|CaseFile
modifier|&
name|Create
parameter_list|(
name|Vdev
modifier|&
name|vdev
parameter_list|)
function_decl|;
comment|/** 	 * \brief Deserialize all serialized CaseFile objects found in 	 *        the file system. 	 */
specifier|static
name|void
name|DeSerialize
parameter_list|()
function_decl|;
comment|/** 	 * \brief Emit syslog data on all active CaseFile%%s in the system. 	 */
specifier|static
name|void
name|LogAll
parameter_list|()
function_decl|;
comment|/** 	 * \brief Destroy the in-core cache of CaseFile data. 	 * 	 * This routine does not disturb the on disk, serialized, CaseFile 	 * data. 	 */
specifier|static
name|void
name|PurgeAll
parameter_list|()
function_decl|;
name|DevdCtl
operator|::
name|Guid
name|PoolGUID
argument_list|()
specifier|const
expr_stmt|;
name|DevdCtl
operator|::
name|Guid
name|VdevGUID
argument_list|()
specifier|const
expr_stmt|;
name|vdev_state
name|VdevState
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|string
operator|&
name|PoolGUIDString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|string
operator|&
name|VdevGUIDString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|string
operator|&
name|PhysicalPath
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * \brief Attempt to resolve this CaseFile using the disk 	 *        resource at the given device/physical path/vdev object 	 *        tuple. 	 * 	 * \param devPath   The devfs path for the disk resource. 	 * \param physPath  The physical path information reported by 	 *                  the disk resource. 	 * \param vdev      If the disk contains ZFS label information, 	 *                  a pointer to the disk label's vdev object 	 *                  data.  Otherwise NULL. 	 * 	 * \return  True if this event was consumed by this CaseFile. 	 */
name|bool
name|ReEvaluate
parameter_list|(
specifier|const
name|string
modifier|&
name|devPath
parameter_list|,
specifier|const
name|string
modifier|&
name|physPath
parameter_list|,
name|Vdev
modifier|*
name|vdev
parameter_list|)
function_decl|;
comment|/** 	 * \brief Update this CaseFile in light of the provided ZfsEvent. 	 * 	 * Must be virtual so it can be overridden in the unit tests 	 * 	 * \param event  The ZfsEvent to evaluate. 	 * 	 * \return  True if this event was consumed by this CaseFile. 	 */
name|virtual
name|bool
name|ReEvaluate
parameter_list|(
specifier|const
name|ZfsEvent
modifier|&
name|event
parameter_list|)
function_decl|;
comment|/** 	 * \brief Register an itimer callout for the given event, if necessary 	 */
name|virtual
name|void
name|RegisterCallout
argument_list|(
specifier|const
name|DevdCtl
operator|::
name|Event
operator|&
name|event
argument_list|)
decl_stmt|;
comment|/** 	 * \brief Close a case if it is no longer relevant. 	 * 	 * This method deals with cases tracking soft errors.  Soft errors 	 * will be discarded should a remove event occur within a short period 	 * of the soft errors being reported.  We also discard the events 	 * if the vdev is marked degraded or failed. 	 * 	 * \return  True if the case is closed.  False otherwise. 	 */
name|bool
name|CloseIfSolved
parameter_list|()
function_decl|;
comment|/** 	 * \brief Emit data about this CaseFile via syslog(3). 	 */
name|void
name|Log
parameter_list|()
function_decl|;
comment|/** 	 * \brief Whether we should degrade this vdev 	 */
name|bool
name|ShouldDegrade
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * \brief Whether we should fault this vdev 	 */
name|bool
name|ShouldFault
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
enum|enum
block|{
comment|/** 		 * The number of soft errors on a vdev required 		 * to transition a vdev from healthy to degraded 		 * status. 		 */
name|ZFS_DEGRADE_IO_COUNT
init|=
literal|50
block|}
enum|;
specifier|static
name|CalloutFunc_t
name|OnGracePeriodEnded
decl_stmt|;
comment|/** 	 * \brief scandir(3) filter function used to find files containing 	 *        serialized CaseFile data. 	 * 	 * \param dirEntry  Directory entry for the file to filter. 	 * 	 * \return  Non-zero for a file to include in the selection, 	 *          otherwise 0. 	 */
specifier|static
name|int
name|DeSerializeSelector
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
name|dirEntry
parameter_list|)
function_decl|;
comment|/** 	 * \brief Given the name of a file containing serialized events from a 	 *        CaseFile object, create/update an in-core CaseFile object 	 *        representing the serialized data. 	 * 	 * \param fileName  The name of a file containing serialized events 	 *                  from a CaseFile object. 	 */
specifier|static
name|void
name|DeSerializeFile
parameter_list|(
specifier|const
name|char
modifier|*
name|fileName
parameter_list|)
function_decl|;
comment|/** Constructor. */
name|CaseFile
argument_list|(
specifier|const
name|Vdev
operator|&
name|vdev
argument_list|)
expr_stmt|;
comment|/** 	 * Destructor. 	 * Must be virtual so it can be subclassed in the unit tests 	 */
name|virtual
operator|~
name|CaseFile
argument_list|()
expr_stmt|;
comment|/** 	 * \brief Reload state for the vdev associated with this CaseFile. 	 * 	 * \return  True if the refresh was successful.  False if the system 	 *          has no record of the pool or vdev for this CaseFile. 	 */
name|virtual
name|bool
name|RefreshVdevState
parameter_list|()
function_decl|;
comment|/** 	 * \brief Free all events in the m_events list. 	 */
name|void
name|PurgeEvents
parameter_list|()
function_decl|;
comment|/** 	 * \brief Free all events in the m_tentativeEvents list. 	 */
name|void
name|PurgeTentativeEvents
parameter_list|()
function_decl|;
comment|/** 	 * \brief Commit to file system storage. 	 */
name|void
name|Serialize
parameter_list|()
function_decl|;
comment|/** 	 * \brief Retrieve event data from a serialization stream. 	 * 	 * \param caseStream  The serializtion stream to parse. 	 */
name|void
name|DeSerialize
argument_list|(
name|std
operator|::
name|ifstream
operator|&
name|caseStream
argument_list|)
decl_stmt|;
comment|/** 	 * \brief Serializes the supplied event list and writes it to fd 	 * 	 * \param prefix  If not NULL, this prefix will be prepended to 	 *                every event in the file. 	 */
name|void
name|SerializeEvList
argument_list|(
specifier|const
name|DevdCtl
operator|::
name|EventList
name|events
argument_list|,
name|int
name|fd
argument_list|,
specifier|const
name|char
operator|*
name|prefix
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/** 	 * \brief Unconditionally close a CaseFile. 	 */
name|virtual
name|void
name|Close
parameter_list|()
function_decl|;
comment|/** 	 * \brief Callout callback invoked when the remove timer grace 	 *        period expires. 	 * 	 * If no remove events are received prior to the grace period 	 * firing, then any tentative events are promoted and counted 	 * against the health of the vdev. 	 */
name|void
name|OnGracePeriodEnded
parameter_list|()
function_decl|;
comment|/** 	 * \brief Attempt to activate a spare on this case's pool. 	 * 	 * Call this whenever a pool becomes degraded.  It will look for any 	 * spare devices and activate one to replace the casefile's vdev.  It 	 * will _not_ close the casefile; that should only happen when the 	 * missing drive is replaced or the user promotes the spare. 	 * 	 * \return True if a spare was activated 	 */
name|bool
name|ActivateSpare
parameter_list|()
function_decl|;
comment|/** 	 * \brief replace a pool's vdev with another 	 * 	 * \param vdev_type   The type of the new vdev.  Usually either 	 *                    VDEV_TYPE_DISK or VDEV_TYPE_FILE 	 * \param path        The file system path to the new vdev 	 * \param isspare     Whether the new vdev is a spare 	 * 	 * \return            true iff the replacement was successful 	 */
name|bool
name|Replace
parameter_list|(
specifier|const
name|char
modifier|*
name|vdev_type
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|isspare
parameter_list|)
function_decl|;
comment|/** 	 * \brief Which vdev, if any, is replacing ours. 	 * 	 * \param zhp		Pool handle state from the caller context 	 * 	 * \return		the vdev that is currently replacing ours, 	 *			or NonexistentVdev if there isn't one. 	 */
name|Vdev
name|BeingReplacedBy
parameter_list|(
name|zpool_handle_t
modifier|*
name|zhp
parameter_list|)
function_decl|;
comment|/** 	 * \brief All CaseFiles being tracked by ZFSD. 	 */
specifier|static
name|CaseFileList
name|s_activeCases
decl_stmt|;
comment|/** 	 * \brief The file system path to serialized CaseFile data. 	 */
specifier|static
specifier|const
name|string
name|s_caseFilePath
decl_stmt|;
comment|/** 	 * \brief The time ZFSD waits before promoting a tentative event 	 *        into a permanent event. 	 */
specifier|static
specifier|const
name|timeval
name|s_removeGracePeriod
decl_stmt|;
comment|/** 	 * \brief A list of soft error events counted against the health of 	 *        a vdev. 	 */
name|DevdCtl
operator|::
name|EventList
name|m_events
expr_stmt|;
comment|/** 	 * \brief A list of soft error events waiting for a grace period 	 *        expiration before being counted against the health of 	 *        a vdev. 	 */
name|DevdCtl
operator|::
name|EventList
name|m_tentativeEvents
expr_stmt|;
name|DevdCtl
operator|::
name|Guid
name|m_poolGUID
expr_stmt|;
name|DevdCtl
operator|::
name|Guid
name|m_vdevGUID
expr_stmt|;
name|vdev_state
name|m_vdevState
decl_stmt|;
name|string
name|m_poolGUIDString
decl_stmt|;
name|string
name|m_vdevGUIDString
decl_stmt|;
name|string
name|m_vdevPhysPath
decl_stmt|;
comment|/** 	 * \brief Callout activated when a grace period 	 */
name|Callout
name|m_tentativeTimer
decl_stmt|;
name|private
label|:
name|nvlist_t
modifier|*
name|CaseVdev
argument_list|(
name|zpool_handle_t
operator|*
name|zhp
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|DevdCtl
operator|::
name|Guid
name|CaseFile
operator|::
name|PoolGUID
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_poolGUID
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DevdCtl
operator|::
name|Guid
name|CaseFile
operator|::
name|VdevGUID
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_vdevGUID
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|vdev_state
name|CaseFile
operator|::
name|VdevState
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_vdevState
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|string
operator|&
name|CaseFile
operator|::
name|PoolGUIDString
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_poolGUIDString
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|string
operator|&
name|CaseFile
operator|::
name|VdevGUIDString
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_vdevGUIDString
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|string
operator|&
name|CaseFile
operator|::
name|PhysicalPath
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_vdevPhysPath
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CASE_FILE_H_ */
end_comment

end_unit

