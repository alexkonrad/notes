//
//  BNRHypnosisView.m
//  Hypnosister
//
//  Created by Alex Konrad on 9/28/14.
//  Copyright (c) 2014 Alex Konrad. All rights reserved.
//

#import "BNRHypnosisView.h"

@interface BNRHypnosisView ()

@property (strong, nonatomic) UIColor *circleColor;

@end

@implementation BNRHypnosisView

-(instancetype) initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.circleColor = [UIColor lightGrayColor];
    }
    return self;
}

- (void)drawRect:(CGRect)rect
{
    CGRect bounds = self.bounds;
    
    CGContextRef currentContext = UIGraphicsGetCurrentContext();
    
    CGContextSaveGState(currentContext);
    CGPoint center;
    center.x = bounds.origin.x + bounds.size.width / 2.0;
    center.y = bounds.origin.y + bounds.size.height / 2.0;
    
    float maxRadius = hypot(bounds.size.width, bounds.size.height) / 2.0;
    
    UIBezierPath *path = [[UIBezierPath alloc] init];
    
    for (float currentRadius = maxRadius; currentRadius > 0; currentRadius -= 20) {
        [path moveToPoint:CGPointMake(center.x + currentRadius, center.y)];
        [path addArcWithCenter:center radius:currentRadius startAngle:0.0 endAngle:M_PI * 2.0 clockwise:YES];
    }
    path.lineWidth = 10;
    [self.circleColor setStroke];
    
    [path stroke];

    CGContextSaveGState(currentContext);
    
    UIBezierPath *trianglePath = [[UIBezierPath alloc] init];
    [trianglePath moveToPoint:CGPointMake(bounds.size.width / 2.0, 75.0)];
    [trianglePath addLineToPoint:CGPointMake(50.0, bounds.size.height - 75.0)];
    [trianglePath addLineToPoint:CGPointMake(bounds.size.width - 50.0, bounds.size.height - 75.0)];
    [trianglePath addLineToPoint:CGPointMake(bounds.size.width / 2.0, 75.0)];
    [trianglePath stroke];
    [trianglePath addClip];
    
    CGFloat locations[2] = { 0.0, 1.0 };
    CGFloat components[8] = { 1.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0 };
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 2);
    
    CGContextSaveGState(currentContext);
    
    CGPoint startPoint = CGPointMake(0.0, 0.0);
    CGPoint endPoint = CGPointMake(0.0, bounds.size.height - 0.0);
    CGContextDrawLinearGradient(currentContext, gradient, startPoint, endPoint, 0);
    CGGradientRelease(gradient);
    CGColorSpaceRelease(colorspace);

    CGContextRestoreGState(currentContext);
    
    CGContextRestoreGState(currentContext);
    
    CGRect imageRect = CGRectMake(100, 160, 200, 100);
    UIImage *logoImage = [UIImage imageNamed:@"/Users/alexkonrad/Dropbox/Photos/Photo 1.jpg"];
    
    CGContextSaveGState(currentContext);
    CGContextSetShadow(currentContext, CGSizeMake(4,7), 3);
    [logoImage drawInRect:imageRect];
    
    CGContextRestoreGState(currentContext);
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    NSLog(@"%@ was touched", self);
    float red = ((arc4random() % 100) / 100.0);
    float green = ((arc4random() % 100) / 100.0);
    float blue = ((arc4random() % 100) / 100.0);
    
    UIColor *randomColor = [UIColor colorWithRed:red
                                    green:green
                                    blue:blue
                                           alpha:1.0];
    self.circleColor = randomColor;
}

- (void)setCircleColor:(UIColor *)circleColor
{
    _circleColor = circleColor;
    [self setNeedsDisplay];
}

@end
