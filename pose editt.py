import cv2
import mediapipe as mp
import time
import math
import serial

mpPose = mp.solutions.pose
mpDraw = mp.solutions.drawing_utils
pose = mpPose.Pose()
ser = serial.Serial('COM3', 9600) 

while True:
    ret, frame = cv2.VideoCapture(0).read()
    frameRGB = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = pose.process(frameRGB)

    if results.pose_landmarks:
        mpDraw.draw_landmarks(frame, results.pose_landmarks, mpPose.POSE_CONNECTIONS)
        landmarks = [lm for lm in results.pose_landmarks.landmark]

        cords = {0: [], 4: [], 6: [], 20: [], 19: [], 3: []}
        for lm in landmarks:
            h, w, c = frame.shape
            cx, cy = int(lm.x * w), int(lm.y * h)
            cords[lm.visibility].append([lm.visibility, cx, cy])

        x_diff_right = cords[0][1][1] - cords[4][1][1]
        y_diff_right = cords[0][1][2] - cords[4][1][2]
        x_diff_left = cords[0][2][1] - cords[6][1][1]
        y_diff_left = cords[0][2][2] - cords[6][1][2]

        if (x_diff_left >= -100 and y_diff_left >= -50) or (x_diff_right <= 100 and y_diff_right >= -50):
            # Hands on face
            cmd = "Hands on face"
        elif (cords[20][1][2] - cords[3][0][2]) <= -1 and (cords[20][1][2] - cords[3][0][2]) >= -5:
            # Hand on waist
            cmd = "Hand on waist"
        else:
            # Other position
            cmd = "Other position"

        # Send the command to the Arduino
        ser.write(cmd.encode())

    ctime = time.time()
    fps = 1 / (ctime - ptime)
    ptime = ctime
    cv2.putText(frame, str(int(fps)), (70, 50), cv2.FONT_HERSHEY_DUPLEX, 1, (0, 0, 0), 1)
    cv2.imshow("Frame", frame)
    cv2.waitKey(1)
