struct __va_list_tag {
    unsigned int field_1;
    unsigned int field_2;
    void * field_3;
    void * field_4;
};

struct _NSZone {
};

struct __AFCFileDescriptor {
};

struct _NSRange {
    unsigned long long field_1;
    unsigned long long field_2;
};

struct __AFCConnection {
};

struct _AMDeviceNotificationContext {
};

struct __AFCOperation {
};

struct _AMDevicePowerAssertion {
};

struct _AMDevice {
};

struct ATHostConnection {
};

struct _AMDServiceConnection {
};

struct __AMRestorableDevice {
};

struct __CFDictionary {
};

struct __AMRestorableBuild {
};



/*****************************************************************/

@protocol NSCopying
- (id)copyWithZone:(struct _NSZone *)v1;
@end


/*****************************************************************/

@interface NSError (MDKVerboseDescription)
+ (id)mdk_formattedCode:(long long)v1;
- (id)mdk_verboseDescription;
- (id)mdk_formattedCode;
- (id)mdk_verboseDescriptionWithIdentation:(unsigned long long)v1;
@end


/*****************************************************************/

@interface NSDictionary (MobileActivation)
- (id)objectForCaseInsensitiveKey:(id)v1;
@end


/*****************************************************************/

@interface MDKManagedConfigService : NSObject {
    MDKServiceConnection * mServiceConnection;
    char mIsAtLeastInnsbruck;
    char mIsAtLeastSochi;
    char _escalated;
}
@property (getter=isEscalated) char escalated;
+ (id)serviceWithConnection:(id)v1 forProductVersion:(id)v2;
- (id)initWithServiceConnection:(id)v1;
- (id)description;
- (char)getInstalledProfileIdentifiers:(id *)v1 andMetadata:(id *)v2 error:(id *)v3;
- (char)installConfigurationProfileData:(id)v1 forceLoudInstallation:(char)v2 error:(id *)v3;
- (char)removeConfigurationProfileWithMetadata:(id)v1 error:(id *)v2;
- (char)helloAndReturnError:(id *)v1;
- (id)deviceInformationForKeys:(id)v1 error:(id *)v2;
- (char)setCloudConfiguration:(id)v1 error:(id *)v2;
- (char)getCloudConfiguration:(id *)v1 error:(id *)v2;
- (char)downloadAndApplyCloudConfigurationWithUsername:(id)v1 password:(id)v2 error:(id *)v3;
- (char)requestProvisionalEnrollmentWithNonce:(id)v1 error:(id *)v2;
- (char)flushAndReturnError:(id *)v1;
- (char)migrateKeybagAndReturnError:(id *)v1;
- (char)clearRestrictionsPasswordAndReturnError:(id *)v1;
- (char)eraseDeviceAndReturnError:(id *)v1;
- (char)changeSettings:(id)v1 error:(id *)v2;
- (char)changeWallpaper:(id)v1 homeScreen:(id)v2 error:(id *)v3;
- (char)clearPasscodeWithUnlockToken:(id)v1 error:(id *)v2;
- (id)retrievePasscodeUnlockTokenAndReturnError:(id *)v1;
- (char)setLanguageWithIdentifier:(id)v1 error:(id *)v2;
- (char)shutDownDeviceAndReturnError:(id *)v1;
- (char)restartDeviceAndReturnError:(id *)v1;
- (char)escalateWithIdentity:(id)v1 error:(id *)v2;
- (char)disconnectAndReturnError:(id *)v1;
- (id)sendRawMessage:(id)v1 error:(id *)v2;
- (void)invalidate;
- (id)errorFromResponse:(id)v1;
- (char)sendMessage:(id)v1 handleResponse:(void (^ /* unknown block signature */)(void))v2 error:(id *)v3;
- (char)sendMessage:(id)v1 error:(id *)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface _MDKLocalizationHelper : NSObject {
    NSDictionary * mEnglishStringByKey;
    NSString * mTable;
}
- (id)stringsForKey:(id)v1 arguments:(struct __va_list_tag[1])v2;
- (id)initWithTable:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKMobileSync : NSObject {
    NSError * mLastError;
    unsigned long long mState;
    NSObject<MDKMobileSyncDelegate> * _delegate;
    NSString * _UDID;
}
@property NSObject<MDKMobileSyncDelegate> * delegate;
@property (readonly,copy) NSString * UDID;
+ (void)initialize;
+ (id)sourcesForRestoreAndReturnError:(id *)v1;
+ (id)deviceInfoForIdentifier:(id)v1;
+ (id)backupInfoForIdentifier:(id)v1 error:(id *)v2;
- (id)initWithUDID:(id)v1 error:(id *)v2;
- (char)restoreFromIdentifier:(id)v1 appIdentifiers:(id)v2 options:(id)v3 error:(id *)v4;
- (char)changeBackupPassword:(id)v1 oldPassword:(id)v2 error:(id *)v3;
- (char)backupWithDeviceInfo:(id)v1 options:(id)v2 error:(id *)v3;
- (char)eraseDeviceWithError:(id *)v1;
- (void)handleProgress:(long long)v1 forIdentifier:(id)v2;
- (void)delegateWillBegin;
- (void)delegateDidProgress:(unsigned long long)v1;
- (void)delegateDidFailWithError:(id)v1;
- (void)delegateDidFinish;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKProvisioningProfile : NSObject {
    id _profileRef;
}
@property (retain,nonatomic) id profileRef;
@property (readonly,copy,nonatomic) NSString * UUID;
@property (readonly,copy,nonatomic) NSDictionary * dictionaryRepresentation;
- (id)initWithData:(id)v1 error:(id *)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKMobileInstallService : NSObject {
    MDKServiceConnection * mServiceConnection;
    NSObject<MDKMobileInstallServiceDelegate> * _delegate;
}
@property NSObject<MDKMobileInstallServiceDelegate> * delegate;
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (void)invalidate;
- (char)transferAppAtURL:(id)v1 usingAFCService:(id)v2 options:(id)v3 error:(id *)v4;
- (char)installAppAtURL:(id)v1 options:(id)v2 error:(id *)v3;
- (char)upgradeAppAtURL:(id)v1 options:(id)v2 error:(id *)v3;
- (char)uninstallAppWithBundleID:(id)v1 error:(id *)v2;
- (id)checkCapabilities:(id)v1 options:(id)v2 error:(id *)v3;
- (void)delegateTransferProgress:(id)v1;
- (void)delegateInstallProgress:(id)v1;
- (void)delegateUninstallProgress:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKSyslogRelayService : NSObject {
    MDKServiceConnection * mServiceConnection;
}
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (void)invalidate;
- (id)newReadDispatchSourceWithQueue:(id)v1;
- (id)readDataWithError:(id *)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKServiceConnection : NSObject {
    struct _AMDServiceConnection * _serviceConnectionRef;
}
@property struct _AMDServiceConnection * serviceConnectionRef;
- (int)socket;
- (id)initWithServiceConnectionRef:(struct _AMDServiceConnection *)v1;
- (void)dealloc;
- (id)description;
- (char)sendMessage:(id)v1 error:(id *)v2;
- (id)receiveMessageAndReturnError:(id *)v1;
- (char)sendData:(id)v1 error:(id *)v2;
- (id)receiveDataWithError:(id *)v1;
- (id)receiveDataOfLength:(unsigned long long)v1 error:(id *)v2;
- (void)invalidate;
@end


/*****************************************************************/

@interface MDKRestorableDevice : NSObject {
    struct __AMRestorableDevice * mRestorableDeviceRef;
    NSTimer * _keepAwakeTimer;
}
@property (retain,nonatomic) NSTimer * keepAwakeTimer;
@property (readonly) NSNumber * ECID;
@property (readonly) NSNumber * locationID;
@property (readonly) unsigned long long state;
@property (readonly) NSNumber * productType;
@property (readonly,nonatomic) NSString * productString;
+ (id)defaultRestoreOptions;
+ (void)enableLogStreaming:(char)v1;
+ (char)setLogFileURL:(id)v1;
- (void)keepDeviceAwake;
- (char)setLogFileURL:(id)v1 logType:(id)v2;
- (id)lookupBoardConfigWithDeviceMap:(id)v1;
- (id)copyMobileDevice;
- (char)sendCommand:(id)v1;
- (char)sendBlindCommand:(id)v1;
- (void)startRestoreWithOptions:(id)v1 delegate:(id)v2;
- (void)presentMobileDeviceUpdater;
- (id)initWithRestorableDeviceRef:(struct __AMRestorableDevice *)v1;
- (void)dealloc;
- (id)description;
- (unsigned long long)hash;
- (char)isEqual:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKAFCFileDescriptor : NSObject {
    struct __AFCFileDescriptor * mFileDescriptorRef;
}
@property (readonly,getter=isValid) char valid;
- (id)initWithFileDescriptorRef:(struct __AFCFileDescriptor *)v1;
- (void)dealloc;
- (id)description;
- (void)invalidate;
- (id)readOperationWithBuffer:(char *)v1 length:(unsigned long long)v2;
- (id)writeOperationWithData:(id)v1;
- (id)seekOperationWithPosition:(long long)v1 direction:(unsigned long long)v2;
- (id)seekPositionOperation;
- (id)setSizeOperationWithSize:(unsigned long long)v1;
- (id)lockOperationWithExclusivity:(char)v1;
- (id)unlockOperation;
- (id)closeOperation;
- (id)setImmutableOperationWithHint:(char)v1;
@end


/*****************************************************************/

@interface MDKMobileDevice : NSObject<NSCopying> {
    struct _AMDevice * mMobileDeviceRef;
    struct _AMDevicePowerAssertion * mPowerAssertionRef;
    NSDate * _connectedDate;
    NSDate * _sessionStartedDate;
    NSTimer * _powerAssertionRenewTimer;
}
@property (retain) NSDate * connectedDate;
@property (retain) NSDate * sessionStartedDate;
@property (retain,nonatomic) NSTimer * powerAssertionRenewTimer;
@property (readonly) NSString * UDID;
@property (readonly,nonatomic,getter=isPlaceholderPairableDevice) char placeholderPairableDevice;
@property (readonly,nonatomic,getter=isDirectlyAttached) char directlyAttached;
+ (id)storebagRequestWithOptions:(id)v1;
+ (id)connectedDevices;
+ (char)shouldRetryAfterError:(id)v1;
- (char)hasConnection;
- (char)hasSession;
- (id)initWithMobileDeviceRef:(struct _AMDevice *)v1;
- (void)dealloc;
- (void)invalidate;
- (id)description;
- (id)debugDescription;
- (unsigned long long)hash;
- (char)isEqual:(id)v1;
- (id)copyWithZone:(struct _NSZone *)v1;
- (id)valueForDomain:(id)v1 andKey:(id)v2 expectedType:(Class)v3 error:(id *)v4;
- (char)setValue:(id)v1 forDomain:(id)v2 andKey:(id)v3 error:(id *)v4;
- (char)removeValueForDomain:(id)v1 andKey:(id)v2 error:(id *)v3;
- (char)performConnectionBlock:(void (^ /* unknown block signature */)(void))v1 error:(id *)v2;
- (char)performConnectionWithRetryCount:(unsigned long long)v1 block:(void (^ /* unknown block signature */)(void))v2 error:(id *)v3;
- (char)connectWithRetryCount:(unsigned long long)v1 error:(id *)v2;
- (char)connectAndReturnError:(id *)v1;
- (void)keepDeviceAwake;
- (void)keepDeviceAwakeFireTimer:(id)v1;
- (char)disconnectAndReturnError:(id *)v1;
- (char)performSessionBlock:(void (^ /* unknown block signature */)(void))v1 error:(id *)v2;
- (char)performSessionWithRetryCount:(unsigned long long)v1 block:(void (^ /* unknown block signature */)(void))v2 error:(id *)v3;
- (char)startSessionWithRetryCount:(unsigned long long)v1 error:(id *)v2;
- (char)startSessionAndReturnError:(id *)v1;
- (char)stopSessionAndReturnError:(id *)v1;
- (char)pairAndReturnError:(id *)v1;
- (char)pairWithOptions:(id)v1 error:(id *)v2;
- (char)verifySecureRemotePasswordPairingSessionAndReturnError:(id *)v1;
- (id)pairWithExtendedOptions:(id)v1 error:(id *)v2;
- (char)unpairAndReturnError:(id *)v1;
- (char)validatePairingAndReturnError:(id *)v1;
- (id)createActivationSessionRequestWithOptions:(id)v1 error:(id *)v2;
- (id)createActivationRequest:(id)v1 options:(id)v2 error:(id *)v3;
- (char)activateWithActivationData:(id)v1 options:(id)v2 error:(id *)v3;
- (char)deactivateAndReturnError:(id *)v1;
- (char)enterRecoveryAndReturnError:(id *)v1;
- (char)installProvisioningProfile:(id)v1 error:(id *)v2;
- (char)uninstallProvisioningProfile:(id)v1 error:(id *)v2;
- (id)newConnectionWithService:(id)v1 options:(id)v2 error:(id *)v3;
- (id)connectToMCInstallServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToNotificationServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToHouseArrestServiceForAppIdentifier:(id)v1 options:(id)v2 error:(id *)v3;
- (id)connectToMediaPartitionServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToMobileInstallServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToSyslogRelayServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToSpringBoardServiceWithOptions:(id)v1 error:(id *)v2;
- (id)connectToMobileProvisioningServiceWithOptions:(id)v1 error:(id *)v2;
- (id)lookupInstalledAppsWithOptions:(id)v1 error:(id *)v2;
- (id)lookupInstalledProvisioningProfiles:(id *)v1;
- (void)updateConnectionAndSessionStateFromError:(int)v1;
- (void)updateConnectionAndSessionStateFromNSError:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKMobileDeviceNotifier : NSObject {
    struct _AMDeviceNotificationContext * mNotificationSubscriptionRef;
    NSObject<OS_dispatch_queue> * mQueue;
    NSObject<MDKMobileDeviceNotifierDelegate> * _delegate;
}
@property NSObject<MDKMobileDeviceNotifierDelegate> * delegate;
- (id)initWithDelegate:(id)v1 connectionType:(int)v2;
- (id)initWithDelegate:(id)v1;
- (id)init;
- (void)subscribeToNotificationsWithConnectionType:(id)v1;
- (void)dealloc;
- (void)invalidate;
- (id)description;
- (void)delegateDidAttachDevice:(id)v1;
- (void)delegateDidDetachDevice:(id)v1;
- (void)delegateDidPairDevice:(id)v1;
- (void)attachDeviceRef:(struct _AMDevice *)v1;
- (void)pairedDevice:(id)v1;
- (void)detachDevice:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKRestorableDeviceNotifier : NSObject {
    int mClientID;
    NSMutableDictionary * mRestorableDevicesByECID;
    NSObject<OS_dispatch_queue> * mQueue;
    NSObject<MDKRestorableDeviceNotifierDelegate> * _delegate;
}
@property NSObject<MDKRestorableDeviceNotifierDelegate> * delegate;
- (id)initWithDelegate:(id)v1 error:(id *)v2;
- (void)dealloc;
- (id)description;
- (char)invalidate;
- (char)registerForNotificationsAndReturnError:(id *)v1;
- (char)unregisterForNotifications;
- (void)presentMobileDeviceUpdaterIfNeeded:(struct __AMRestorableDevice *)v1;
- (void)attachDeviceRef:(struct __AMRestorableDevice *)v1;
- (void)detachDeviceRef:(struct __AMRestorableDevice *)v1;
- (void)delegateDidAttachDevice:(id)v1;
- (void)delegateDidDetachDevice:(id)v1;
- (void)delegateWillStart;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKATCMessage : NSObject {
    struct __CFDictionary * _messageRef;
}
@property struct __CFDictionary * messageRef;
@property (readonly) NSString * name;
@property (readonly) unsigned long long sessionNumber;
@property (readonly) NSDictionary * dictionaryRepresentation;
- (id)initWithATCFMessageRef:(struct __CFDictionary *)v1;
- (id)initWithSessionNumber:(unsigned long long)v1 name:(id)v2 params:(id)v3;
- (void)dealloc;
- (id)description;
- (id)valueForKey:(id)v1;
@end


/*****************************************************************/

@interface MDKMobileProvisioningService : NSObject {
    MDKServiceConnection * mServiceConnection;
}
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (void)invalidate;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKNotificationService : NSObject {
    MDKServiceConnection * mServiceConnection;
    NSObject<OS_dispatch_queue> * mQueue;
    NSObject<OS_dispatch_queue> * mEventQueue;
    char mListening;
    NSObject<MDKNotificationServiceDelegate> * _delegate;
    NSObject<OS_dispatch_queue> * _delegateQueue;
}
@property NSObject<MDKNotificationServiceDelegate> * delegate;
@property (retain) NSObject<OS_dispatch_queue> * delegateQueue;
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (char)postNotificationNamed:(id)v1 userInfo:(id)v2 error:(id *)v3;
- (char)observeNotifications:(id)v1 error:(id *)v2;
- (void)invalidate;
- (char)startListeningForNotificationsAndReturnError:(id *)v1;
- (char)stopListeningForNotificationsAndReturnError:(id *)v1;
- (void)handleNotificationWithName:(id)v1;
- (void)delegateDidDisconnect;
- (void)delegateDidReceiveNotificationWithName:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface _MDKNotificationServiceHelper : NSObject {
    NSObject<OS_dispatch_semaphore> * mSemaphore;
    NSMapTable * mServiceByKey;
}
+ (id)sharedHelper;
- (id)init;
- (void)registerService:(id)v1;
- (void)forwardNotification:(id)v1 forKey:(unsigned long long)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKAFCOperation : NSObject {
    struct __AFCOperation * _operationRef;
}
@property struct __AFCOperation * operationRef;
@property (readonly) unsigned long long state;
@property (readonly) unsigned long long resultStatus;
@property (readonly) id resultObject;
- (id)initWithOperationRef:(struct __AFCOperation *)v1;
- (void)dealloc;
- (id)createPacketHeaderDictionary;
- (id)copyPacketData;
- (id)description;
@end


/*****************************************************************/

@interface MDKAFCGetDeviceInfoOperation : MDKAFCOperation
- (id)init;
@end


/*****************************************************************/

@interface MDKAFCGetConnectionInfoOperation : MDKAFCOperation
- (id)init;
@end


/*****************************************************************/

@interface MDKAFCSetConnectionOptionsOperation : MDKAFCOperation
- (id)initWithOptions:(id)v1;
@end


/*****************************************************************/

@interface MDKAFCGetFileInfoOperation : MDKAFCOperation
- (id)initWithPath:(id)v1;
@end


/*****************************************************************/

@interface MDKAFCOpenFileOperation : MDKAFCOperation
- (id)initWithPath:(id)v1 mode:(unsigned long long)v2;
@end


/*****************************************************************/

@interface MDKAFCRemovePathOperation : MDKAFCOperation
- (id)initWithPath:(id)v1;
- (id)initWithPath:(id)v1 recursive:(char)v2;
@end


/*****************************************************************/

@interface MDKAFCRenamePathOperation : MDKAFCOperation
- (id)initWithSourcePath:(id)v1 toDestinationPath:(id)v2;
@end


/*****************************************************************/

@interface MDKAFCSetModTimeForPathOperation : MDKAFCOperation
- (id)initWithPath:(id)v1 time:(double)v2;
@end


/*****************************************************************/

@interface MDKAFCLinkPathOperation : MDKAFCOperation
- (id)initWithPath:(id)v1 toPath:(id)v2 linkType:(long long)v3;
- (id)initWithPath:(id)v1 linkToPath:(id)v2;
- (id)initWithPath:(id)v1 symbolicLinkToPath:(id)v2;
@end


/*****************************************************************/

@interface MDKAFCReadDirectoryOperation : MDKAFCOperation
- (id)initWithPath:(id)v1;
@end


/*****************************************************************/

@interface MDKAFCMakeDirectoryOperation : MDKAFCOperation
- (id)initWithPath:(id)v1;
@end


/*****************************************************************/

@interface MDKAFCGetFileHashOperation : MDKAFCOperation
- (id)initWithPath:(id)v1;
- (id)initWithPath:(id)v1 range:(struct _NSRange)v2;
@end


/*****************************************************************/

@interface MDKAFCGetSizeOfPathContentsOperation : MDKAFCOperation
- (id)initWithPath:(id)v1 recursive:(char)v2;
@end


/*****************************************************************/

@interface MDKSpringBoardService : NSObject {
    MDKServiceConnection * mServiceConnection;
}
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (id)homeScreenMetricsWithError:(id *)v1;
- (id)iconStateWithError:(id *)v1;
- (char)setIconState:(id)v1 error:(id *)v2;
- (id)iconImageDataForBundleID:(id)v1 error:(id *)v2;
- (id)interfaceOrientationWithError:(id *)v1;
- (id)homeScreenWallpaperImageDataWithError:(id *)v1;
- (id)lockScreenWallpaperImageDataWithError:(id *)v1;
- (void)invalidate;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKRestorableBuild : NSObject {
    struct __AMRestorableBuild * mRestorableBuildRef;
}
- (id)initWithRestorableBuildRef:(struct __AMRestorableBuild *)v1;
- (id)initWithURL:(id)v1 error:(id *)v2;
- (void)dealloc;
- (id)supportedVariantsForBoardConfig:(id)v1 error:(id *)v2;
- (id)supportedBoardConfigsAndReturnError:(id *)v1;
- (id)restoreBundleURLForBoardConfig:(id)v1 variantName:(id)v2 error:(id *)v3;
@end


/*****************************************************************/

@interface MDKAFCService : NSObject {
    MDKServiceConnection * mServiceConnection;
    NSObject<MDKAFCServiceDelegate> * _delegate;
    struct __AFCConnection * _connectionRef;
}
@property struct __AFCConnection * connectionRef;
@property NSObject<MDKAFCServiceDelegate> * delegate;
@property double timeoutInterval;
@property (readonly,getter=isValid) char valid;
- (id)initWithConnectionRef:(struct __AFCConnection *)v1;
- (id)initWithServiceConnection:(id)v1;
- (void)dealloc;
- (void)invalidate;
- (void)scheduleInRunLoop:(id)v1 forMode:(id)v2;
- (void)removeFromeRunLoop:(id)v1 forMode:(id)v2;
- (char)submitOperation:(id)v1 error:(id *)v2;
- (char)processOperation:(id)v1 timeoutInterval:(double)v2 error:(id *)v3;
- (char)processOperationsWithTimeoutInterval:(double)v1 error:(id *)v2;
- (id)description;
- (void)delegateDidCompleteOperation:(id)v1;
- (void)delegateDidInvalidate;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MDKATHostConnection : NSObject {
    struct ATHostConnection * mHostConnectionRef;
    NSString * mDeviceUDID;
}
@property (readonly) unsigned long long grappaSessionID;
+ (void)initialize;
- (unsigned long long)sessionNumber;
- (id)initWithDeviceUDID:(id)v1 libraryIdentifier:(id)v2;
- (void)dealloc;
- (id)description;
- (void)sendSyncRequestWithDataClasses:(id)v1 anchors:(id)v2 hostInfo:(id)v3;
- (void)sendMetadataSyncFinishedWithSyncTypes:(id)v1 newAnchors:(id)v2 purgeableSize:(id)v3;
- (void)sendFileCompletedForAssetID:(id)v1 dataClass:(id)v2 assetPath:(id)v3;
- (void)sendFileCompletedForAssetID:(id)v1 dataClass:(id)v2 assetPath:(id)v3 metadata:(id)v4 newAnchor:(id)v5;
- (void)sendFileBeginForAssetID:(id)v1 dataClass:(id)v2 fileSize:(unsigned long long)v3 totalBytes:(unsigned long long)v4;
- (void)sendFileProgressForAssetID:(id)v1 dataClass:(id)v2 progress:(double)v3 overallProgress:(double)v4;
- (void)sendFileErrorForAssetID:(id)v1 dataClass:(id)v2 errorCode:(int)v3;
- (void)sendSyncFailedWithErrorCode:(int)v1;
- (void)sendAssetMetricsRequestWithDataClasses:(id)v1;
- (void)sendStatusMessage:(id)v1;
- (void)sendPing;
- (void)sendPong;
- (void)sendMessage:(id)v1;
- (id)readMessage;
- (void)invalidate;
- (void).cxx_destruct;
@end
