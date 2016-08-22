//
//  RRTexture.h
//
//  Copyright (c) 2016 HelpURock. All rights reserved.
//
//  This module holds instance references to an already encoded texture.
//  The caller creates an instance of a texture either before associating
//  with a node or at some init time before the node is created.

@import SpriteKit;
@import ImageIO;
@import MobileCoreServices;

@interface RRTexture : NSObject

// size indicate the original texture width and height in pixels

@property (nonatomic, assign) CGSize pixelSize;

// texture size in points

@property (nonatomic, assign) CGSize pointSize;

// adler32 checksum for input pixels

@property (nonatomic, assign) uint32_t adler32;

// SpriteKit texture object that contains the compressed texture

@property (nonatomic, retain) SKTexture *skTexture;

// SpriteKit shader instance compiled after compressed texture is generated

@property (nonatomic, retain) SKShader *shader;

// Encode time options

@property (nonatomic, copy) NSDictionary *options;

// Encode a compressed texture as a NSData and prepare a
// compiled texture shader object.

+ (RRTexture*) encodeTexture:(NSDictionary*)options
                     results:(NSMutableDictionary*)results;

// Decode an already compressed texture that is included
// in a spacific bundle and resource name as indicated
// in the passed in options.

+ (RRTexture*) decodeTexture:(NSDictionary*)options
                     results:(NSMutableDictionary*)results;

// Adler32 checksum

+ (uint32_t) adlerForData:(NSData*)data;

@end
