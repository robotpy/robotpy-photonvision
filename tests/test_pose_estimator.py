import robotpy_apriltag
from wpimath.geometry import Transform3d

import photonvision


def test_photon_pose_estimator_ctor():
    camera = photonvision.PhotonCamera("test_ctor")
    assert camera._path
    estimator = photonvision.PhotonPoseEstimator(
        robotpy_apriltag.loadAprilTagLayoutField(
            robotpy_apriltag.AprilTagField.k2023ChargedUp
        ),
        photonvision.PoseStrategy.AVERAGE_BEST_TARGETS,
        camera,
        Transform3d(),
    )
    assert estimator
    assert camera._path


def test_photon_pose_estimator_update():
    estimator = photonvision.PhotonPoseEstimator(
        robotpy_apriltag.loadAprilTagLayoutField(
            robotpy_apriltag.AprilTagField.k2023ChargedUp
        ),
        photonvision.PoseStrategy.AVERAGE_BEST_TARGETS,
        photonvision.PhotonCamera("test_update"),
        Transform3d(),
    )
    assert estimator.update() is None


def test_photon_pose_estimator_get_cam():
    camera = photonvision.PhotonCamera("test_get_cam")
    estimator = photonvision.PhotonPoseEstimator(
        robotpy_apriltag.loadAprilTagLayoutField(
            robotpy_apriltag.AprilTagField.k2023ChargedUp
        ),
        photonvision.PoseStrategy.AVERAGE_BEST_TARGETS,
        camera,
        Transform3d(),
    )
    inner_cam = estimator.getCamera()
    assert inner_cam is camera
