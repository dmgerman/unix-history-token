begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013, 2016 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file devdctl_event.h  *  * \brief Class hierarchy used to express events received via  *        the devdctl API.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVDCTL_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEVDCTL_EVENT_H_
end_define

begin_comment
comment|/*============================ Namespace Control =============================*/
end_comment

begin_decl_stmt
name|namespace
name|DevdCtl
block|{
comment|/*=========================== Forward Declarations ===========================*/
name|class
name|EventFactory
decl_stmt|;
comment|/*============================= Class Definitions ============================*/
comment|/*-------------------------------- NVPairMap ---------------------------------*/
comment|/**  * NVPairMap is a specialization of the standard map STL container.  */
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
name|NVPairMap
expr_stmt|;
comment|/*----------------------------------- Event ----------------------------------*/
comment|/**  * \brief Container for the name => value pairs that comprise the content of  *        a device control event.  *  * All name => value data for events can be accessed via the Contains()  * and Value() methods.  name => value pairs for data not explicitly  * received as a name => value pair are synthesized during parsing.  For  * example, ATTACH and DETACH events have "device-name" and "parent"  * name => value pairs added.  */
name|class
name|Event
block|{
name|friend
name|class
name|EventFactory
decl_stmt|;
name|public
label|:
comment|/** Event type */
enum|enum
name|Type
block|{
comment|/** Generic event notification. */
name|NOTIFY
init|=
literal|'!'
block|,
comment|/** A driver was not found for this device. */
name|NOMATCH
init|=
literal|'?'
block|,
comment|/** A bus device instance has been added. */
name|ATTACH
init|=
literal|'+'
block|,
comment|/** A bus device instance has been removed. */
name|DETACH
init|=
literal|'-'
block|}
enum|;
comment|/** 	 * Factory method type to construct an Event given 	 * the type of event and an NVPairMap populated from 	 * the event string received from devd. 	 */
typedef|typedef
name|Event
argument_list|*
call|(
name|BuildMethod
call|)
argument_list|(
name|Type
argument_list|,
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|;
comment|/** Generic Event object factory. */
specifier|static
name|BuildMethod
name|Builder
argument_list|;
specifier|static
name|Event
operator|*
name|CreateEvent
argument_list|(
specifier|const
name|EventFactory
operator|&
name|factory
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|eventString
argument_list|)
argument_list|;
comment|/** 	 * Returns the devname, if any, associated with the event 	 * 	 * \param name	Devname, returned by reference 	 * \return	True iff the event contained a devname 	 */
name|virtual
name|bool
name|DevName
argument_list|(
argument|std::string&name
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * Returns the absolute pathname of the device associated with this 	 * event. 	 * 	 * \param name	Devname, returned by reference 	 * \return	True iff the event contained a devname 	 */
name|bool
name|DevPath
argument_list|(
argument|std::string&path
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * Returns true iff this event refers to a disk device 	 */
name|bool
name|IsDiskDev
argument_list|()
specifier|const
argument_list|;
comment|/** Returns the physical path of the device, if any 	 * 	 * \param path	Physical path, returned by reference 	 * \return	True iff the event contains a device with a physical 	 * 		path 	 */
name|bool
name|PhysicalPath
argument_list|(
argument|std::string&path
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * Provide a user friendly string representation of an 	 * event type. 	 * 	 * \param type  The type of event to map to a string. 	 * 	 * \return  A user friendly string representing the input type. 	 */
specifier|static
specifier|const
name|char
operator|*
name|TypeToString
argument_list|(
argument|Type type
argument_list|)
argument_list|;
comment|/** 	 * Determine the availability of a name => value pair by name. 	 * 	 * \param name  The key name to search for in this event instance. 	 * 	 * \return  true if the specified key is available in this 	 *          event, otherwise false. 	 */
name|bool
name|Contains
argument_list|(
argument|const std::string&name
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * \param key  The name of the key for which to retrieve its 	 *             associated value. 	 * 	 * \return  A const reference to the string representing the 	 *          value associated with key. 	 * 	 * \note  For key's with no registered value, the empty string 	 *        is returned. 	 */
specifier|const
name|std
operator|::
name|string
operator|&
name|Value
argument_list|(
argument|const std::string&key
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * Get the type of this event instance. 	 * 	 * \return  The type of this event instance. 	 */
name|Type
name|GetType
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Get the original DevdCtl event string for this event. 	 * 	 * \return  The DevdCtl event string. 	 */
specifier|const
name|std
operator|::
name|string
operator|&
name|GetEventString
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Convert the event instance into a string suitable for 	 * printing to the console or emitting to syslog. 	 * 	 * \return  A string of formatted event data. 	 */
name|std
operator|::
name|string
name|ToString
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Pretty-print this event instance to cout. 	 */
name|void
name|Print
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Pretty-print this event instance to syslog. 	 * 	 * \param priority  The logging priority/facility. 	 *                  See syslog(3). 	 */
name|void
name|Log
argument_list|(
argument|int priority
argument_list|)
specifier|const
argument_list|;
comment|/** 	 * Create and return a fully independent clone 	 * of this event. 	 */
name|virtual
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
argument_list|;
comment|/** Destructor */
name|virtual
operator|~
name|Event
argument_list|()
argument_list|;
comment|/** 	 * Interpret and perform any actions necessary to 	 * consume the event. 	 * 	 * \return True if this event should be queued for later reevaluation 	 */
name|virtual
name|bool
name|Process
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Get the time that the event was created 	 */
name|timeval
name|GetTimestamp
argument_list|()
specifier|const
argument_list|;
comment|/** 	 * Add a timestamp to the event string, if one does not already exist 	 * TODO: make this an instance method that operates on the std::map 	 * instead of the string.  We must fix zfsd's CaseFile serialization 	 * routines first, so that they don't need the raw event string. 	 * 	 * \param[in,out] eventString The devd event string to modify 	 */
specifier|static
name|void
name|TimestampEventString
argument_list|(
name|std
operator|::
name|string
operator|&
name|eventString
argument_list|)
argument_list|;
comment|/** 	 * Access all parsed key => value pairs. 	 */
specifier|const
name|NVPairMap
operator|&
name|GetMap
argument_list|()
specifier|const
argument_list|;
name|protected
operator|:
comment|/** Table entries used to map a type to a user friendly string. */
expr|struct
name|EventTypeRecord
block|{
name|Type
name|m_type
block|;
specifier|const
name|char
operator|*
name|m_typeName
block|; 	}
argument_list|;
comment|/** 	 * Constructor 	 * 	 * \param type  The type of event to create. 	 */
name|Event
argument_list|(
argument|Type type
argument_list|,
argument|NVPairMap&map
argument_list|,
argument|const std::string&eventString
argument_list|)
argument_list|;
comment|/** Deep copy constructor. */
name|Event
argument_list|(
specifier|const
name|Event
operator|&
name|src
argument_list|)
argument_list|;
comment|/** Always empty string returned when NVPairMap lookups fail. */
specifier|static
specifier|const
name|std
operator|::
name|string
name|s_theEmptyString
argument_list|;
comment|/** Unsorted table of event types. */
specifier|static
name|EventTypeRecord
name|s_typeTable
index|[]
argument_list|;
comment|/** The type of this event. */
specifier|const
name|Type
name|m_type
argument_list|;
comment|/** 	 * Event attribute storage. 	 * 	 * \note Although stored by reference (since m_nvPairs can 	 *       never be NULL), the NVPairMap referenced by this field 	 *       is dynamically allocated and owned by this event object. 	 *       m_nvPairs must be deleted at event destruction. 	 */
name|NVPairMap
operator|&
name|m_nvPairs
argument_list|;
comment|/** 	 * The unaltered event string, as received from devd, used to 	 * create this event object. 	 */
name|std
operator|::
name|string
name|m_eventString
argument_list|;
name|private
operator|:
comment|/** 	 * Ingest event data from the supplied string. 	 * 	 * \param[in] eventString  The string of devd event data to parse. 	 * \param[out] nvpairs     Returns the parsed data 	 */
specifier|static
name|void
name|ParseEventString
argument_list|(
argument|Type type
argument_list|,
argument|const std::string&eventString
argument_list|,
argument|NVPairMap&nvpairs
argument_list|)
argument_list|;
block|}
empty_stmt|;
specifier|inline
name|Event
operator|::
name|Type
name|Event
operator|::
name|GetType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_type
operator|)
return|;
block|}
specifier|inline
specifier|const
name|std
operator|::
name|string
operator|&
name|Event
operator|::
name|GetEventString
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_eventString
operator|)
return|;
block|}
specifier|inline
specifier|const
name|NVPairMap
operator|&
name|Event
operator|::
name|GetMap
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_nvPairs
operator|)
return|;
block|}
comment|/*--------------------------------- EventList --------------------------------*/
comment|/**  * EventList is a specialization of the standard list STL container.  */
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Event
operator|*
operator|>
name|EventList
expr_stmt|;
comment|/*-------------------------------- DevfsEvent --------------------------------*/
name|class
name|DevfsEvent
range|:
name|public
name|Event
block|{
name|public
operator|:
comment|/** Specialized Event object factory for Devfs events. */
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
comment|/** 	 * Interpret and perform any actions necessary to 	 * consume the event. 	 * \return True if this event should be queued for later reevaluation 	 */
name|virtual
name|bool
name|Process
argument_list|()
specifier|const
block|;
name|bool
name|IsWholeDev
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|DevName
argument_list|(
argument|std::string&name
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|/** 	 * Given the device name of a disk, determine if the device 	 * represents the whole device, not just a partition. 	 * 	 * \param devName  Device name of disk device to test. 	 * 	 * \return  True if the device name represents the whole device. 	 *          Otherwise false. 	 */
specifier|static
name|bool
name|IsWholeDev
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|devName
argument_list|)
block|;
comment|/** DeepCopy Constructor. */
name|DevfsEvent
argument_list|(
specifier|const
name|DevfsEvent
operator|&
name|src
argument_list|)
block|;
comment|/** Constructor */
name|DevfsEvent
argument_list|(
name|Type
argument_list|,
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
block|; }
decl_stmt|;
comment|/*--------------------------------- GeomEvent --------------------------------*/
name|class
name|GeomEvent
range|:
name|public
name|Event
block|{
name|public
operator|:
comment|/** Specialized Event object factory for GEOM events. */
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|DevName
argument_list|(
argument|std::string&name
argument_list|)
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|DeviceName
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|/** Constructor */
name|GeomEvent
argument_list|(
name|Type
argument_list|,
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
block|;
comment|/** Deep copy constructor. */
name|GeomEvent
argument_list|(
specifier|const
name|GeomEvent
operator|&
name|src
argument_list|)
block|;
name|std
operator|::
name|string
name|m_devname
block|; }
decl_stmt|;
comment|/*--------------------------------- ZfsEvent ---------------------------------*/
name|class
name|ZfsEvent
range|:
name|public
name|Event
block|{
name|public
operator|:
comment|/** Specialized Event object factory for ZFS events. */
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|DevName
argument_list|(
argument|std::string&name
argument_list|)
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|PoolName
argument_list|()
specifier|const
block|;
name|Guid
name|PoolGUID
argument_list|()
specifier|const
block|;
name|Guid
name|VdevGUID
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|/** Constructor */
name|ZfsEvent
argument_list|(
name|Type
argument_list|,
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
block|;
comment|/** Deep copy constructor. */
name|ZfsEvent
argument_list|(
specifier|const
name|ZfsEvent
operator|&
name|src
argument_list|)
block|;
name|Guid
name|m_poolGUID
block|;
name|Guid
name|m_vdevGUID
block|; }
decl_stmt|;
comment|//- ZfsEvent Inline Public Methods --------------------------------------------
specifier|inline
specifier|const
name|std
operator|::
name|string
operator|&
name|ZfsEvent
operator|::
name|PoolName
argument_list|()
specifier|const
block|{
comment|/* The pool name is reported as the subsystem of ZFS events. */
return|return
operator|(
name|Value
argument_list|(
literal|"subsystem"
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|Guid
name|ZfsEvent
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
specifier|inline
name|Guid
name|ZfsEvent
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
block|}
end_decl_stmt

begin_comment
comment|// namespace DevdCtl
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DEVDCTL_EVENT_H_ */
end_comment

end_unit

