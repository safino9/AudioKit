//
//  OCSNote.h
//  OCS iPad Examples
//
//  Created by Aurelius Prochazka on 9/18/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

#import "OCSInstrument.h"
#import "OCSNoteProperty.h"

/** OCSNote is a representation of a sound object that is created by an
 OCSInstrument and has at least one of the two following qualities:
 a) The note has a duration, it starts and some finite time later, it ends.
 b) The note is created concurrently with other notes created by the instrument
 */

@interface OCSNote : NSObject

/// Instrument this note belongs to
@property (nonatomic, strong) OCSInstrument *instrument;

/// Duration of this note (for finite notes with length defined)
@property (nonatomic, strong) OCSConstant *duration;

/// Set of properties of the note
@property (nonatomic, strong) NSMutableDictionary *properties;

/// Unique Identifier for the event
@property (readonly) float eventNumber;

// -----------------------------------------------------------------------------
#  pragma mark - Initialization
// -----------------------------------------------------------------------------

/// Allows the unique identifying integer to be reset so that the numbers don't increment indefinitely.
+ (void)resetID;

/// Creates the note associated with the given instrument
/// @param anInstrument This note's instrument.
/// @param noteDuration Length of time to play the note in seconds
- (id)initWithInstrument:(OCSInstrument *)anInstrument
             forDuration:(OCSConstant *)noteDuration;

/// Creates the note associated with the given instrument
/// @param anInstrument This note's instrument.
- (id)initWithInstrument:(OCSInstrument *)anInstrument;


/// Begin playback of the note.
- (void)play;

/// Stop playback of the note.
- (void)stop;

/// Returns the playback scoreline to the CSD File.
- (NSString *)stringForCSD;

/// Returns the stop scoreline to the CSD File.
- (NSString *)stopStringForCSD;

/// Adds the property to the list of available properties of the note
/// @param newProperty New property to add to the note's set of properties
/// @param name        Human readable name for the of the property
- (void) addProperty:(OCSNoteProperty *)newProperty
            withName:(NSString *)name;

@end