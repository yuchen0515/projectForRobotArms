#include <Servo.h>
#include <Math.h>

Servo servo_a;
Servo servo_b;
Servo servo_c;
Servo servo_f;

bool robotArmTouchGround (
    double l1,
    double l2,
    double theta1,
    double theta2,
    double B) {

    double rad1 = theta1 * (M_PI / 180.0);
    double rad2 = theta2 * (M_PI / 180.0);

    double s1 = l1 * sin(rad1);
    double s2 = l2 * sin(rad2);

    if (s1 >= s2) {
        return false;
    }

    if (s2 - s1 < B) {
        return false;
    }

    return true;
}

void setup() {

    //motor
    Serial.begin(9600);

    servo_a.attach(10);
    servo_a.write(90);
    servo_b.attach(11);
    servo_b.write(90);
    servo_c.attach(12);
    servo_c.write(46);
    servo_f.attach(13);
    servo_f.write(0);

    //joystick  
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}

// the loop function runs over and over again forever
void loop() {
    int a = servo_a.read();
    int b = servo_b.read();
    int c = servo_c.read();
    int f = servo_f.read();

    // You could define l1, l2, B the specified number.
    const double l1 = 1.5;
    const double l2 = 1.8;
    const double B = 2.0;
    // And the angle put the above a, b, c, or f

    // if (robotArmTouchGround(l1, l2, a, b, B) == true) {
    //      maybe you can call the delay with 750 ms or 800 ms
    //    continue;
    // }


    //servo_a
    if (digitalRead(4) == 0) {
        a += 2;
        if (a > 180) {
            a = 180;
        }
        servo_a.write(a);
    }
    if (digitalRead(5) == 0) {
        a -= 2;
        if (a < 0) {
            a = 0;
        }
        servo_a.write(a);
    } 
    //delay(20);
    Serial.print("a=");
    Serial.print(servo_a.read());
    Serial.print("\t");

    //servo_b
    if (digitalRead(2) == 0) {
        b += 2;
        if (b > 180) {
            b = 180;
        }
        servo_b.write(b);
    }
    if (digitalRead(3) == 0) {
        b -= 2;
        if (b < 80) {
            b = 80;
        }
        servo_b.write(b);
    } 
    //delay(20);
    Serial.print("b=");
    Serial.print(servo_b.read());
    Serial.print("\t");

    //servo_c
    if (digitalRead(6) == 0) {
        c -= 2;
        if (c < 2) {
            c = 2;
        }
        servo_c.write(c);
    }
    if (digitalRead(7) == 0) {
        c += 2;
        if (c > 150) {
            c = 150;
        }
        servo_c.write(c);
    }

    Serial.print("c=");
    Serial.print(servo_c.read());
    Serial.print("\t");

    //servo_f
    if (digitalRead(9) == 0) {
        f += 2;
        if (f > 84) {
            f = 84;
        }
        servo_f.write(f);  
    }
    if (digitalRead(8) == 0) {
        f -= 2;
        if (f < 0) {
            f = 0;
        }
        servo_f.write(f);
    } 
    delay(20);
    Serial.print("f=");
    Serial.println(servo_f.read()); 
}

//after 30 come back
