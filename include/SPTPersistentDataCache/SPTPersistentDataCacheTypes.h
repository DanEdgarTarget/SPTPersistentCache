/*
 * Copyright (c) 2016 Spotify AB.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const SPTPersistentDataCacheErrorDomain;

/**
 * Default garbage collection interval. Some sane implementation defined value you should not care about.
 */
FOUNDATION_EXPORT const NSUInteger SPTPersistentDataCacheDefaultGCIntervalSec;

/**
 * Default exparation interval for all cache items. Particular record's TTL takes precedence over this value.
 * Items stored without (tt=0) TTL considered as expired if following is true: current_time - update_time > ExpInterval.
 */
FOUNDATION_EXPORT const NSUInteger SPTPersistentDataCacheDefaultExpirationTimeSec;


/**
 @enum SPTPersistentDataCacheResponseCode

 @discussion The SPTPersistentDataCacheResponseCode enum defines constants that
 is used to identify what kind of response would be given in callback to
 loadDataForKey:withCallback: method.

 @constant SPTPersistentDataCacheResponseCodeOperationSucceeded Indicates success of requested operation with data.
 record field of SPTPersistentCacheResponse mustn't be nil if it was load operation otherwise it could be. error would
 be nil.

 @constant SPTPersistentDataCacheResponseCodeNotFound Indicates that no file found for given key in cache or is expired.
 record and error field of SPTPersistentCacheResponse is nil in this case.

 @constant SPTPersistentDataCacheResponseCodeOperationError Indicates error occured during requested operation.
 record field of SPTPersistentCacheResponse would be nil. error mustn't be nil and specify exact error.
 */
typedef NS_ENUM(NSInteger, SPTPersistentDataCacheResponseCode) {
    SPTPersistentDataCacheResponseCodeOperationSucceeded,
    SPTPersistentDataCacheResponseCodeNotFound,
    SPTPersistentDataCacheResponseCodeOperationError
};

/**
 @enum SPTPersistentDataCacheLoadingError

 @discussion The SPTPersistentDataCacheLoadingError enum defines constants that
 identify NSError's in SPTPersistentDataCacheErrorDomain.

 @constant SPTPersistentDataCacheLoadingErrorMagicMismatch Magic number in record header is not as expected which means
 file is not readable by this cache.

 @constant SPTPersistentDataCacheLoadingErrorHeaderAlignmentMismatch Alignment of pointer which casted to header
 is not compatible with alignment of first header field. This actually is insane but who knows.

 @constant SPTPersistentDataCacheLoadingErrorWrongHeaderSize Size of header is not as expected. Possibly bcuz of version change.

 @constant SPTPersistentDataCacheLoadingErrorWrongPayloadSize Payload size in header is not the same as stored in cache record.

 @constant SPTPersistentDataCacheLoadingErrorInvalidHeaderCRC CRC calculated for reader and contained in header are different.

 @constant SPTPersistentDataCacheLoadingErrorNotEnoughDataToGetHeader Binary data size read as header is less then current header
 size which means we can't proceed further with this file.

 @constant SPTPersistentDataCacheLoadingErrorRecordIsStreamAndBusy Record is opened as stream and busy right now.

 @constant SPTPersistentDataCacheLoadingErrorInternalInconsistency Something bad has happened that shouldn't.
 */
typedef NS_ENUM(NSInteger, SPTPersistentDataCacheLoadingError) {
    SPTPersistentDataCacheLoadingErrorMagicMismatch = 100,
    SPTPersistentDataCacheLoadingErrorHeaderAlignmentMismatch,
    SPTPersistentDataCacheLoadingErrorWrongHeaderSize,
    SPTPersistentDataCacheLoadingErrorWrongPayloadSize,
    SPTPersistentDataCacheLoadingErrorInvalidHeaderCRC,
    SPTPersistentDataCacheLoadingErrorNotEnoughDataToGetHeader,
    SPTPersistentDataCacheLoadingErrorRecordIsStreamAndBusy,
    SPTPersistentDataCacheLoadingErrorInternalInconsistency
};
