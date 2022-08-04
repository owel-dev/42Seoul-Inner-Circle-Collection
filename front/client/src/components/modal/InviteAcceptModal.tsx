import { useEffect } from 'react';
import { Navigate } from 'react-router-dom';
import { useRecoilState, useSetRecoilState } from 'recoil';
import { channelState, inviteState } from 'utils/recoil/gameState';
import { inviteType } from 'types/GameTypes';
import { modalState } from 'utils/recoil/modal';
import { socket } from 'components/layout/Layout';
import 'styles/modal/Modal.css';

function InviteAcceptModal() {
  const [inviteData, setInviteData] = useRecoilState<inviteType>(inviteState);
  const [channelInfo, setChannelInfo] = useRecoilState(channelState);
  const setModalState = useSetRecoilState(modalState);

  const inviteAccept = () => {
    socket.emit('together-response', { status: true, data: inviteData });
  };
  const inviteDeny = () => {
    socket.emit('together-response', { status: false, data: inviteData });
    setModalState({ modalName: null });
  };

  useEffect(() => {
    socket.on('game-wait', (data) => {
      setChannelInfo(data);
    });
  }, [setChannelInfo]);

  return (
    <>
      {channelInfo.channelId ? (
        <Navigate to={'/channel/' + channelInfo.channelId} />
      ) : (
        <div className='modal'>
          <div className='modalTitle'>Invite Accept</div>
          <div className='modalContent'>
            {inviteData.nickName}님의 초대를 수락겠습니까?
          </div>
          <div className='modalSelect'>
            <button className='modalButton' onClick={inviteAccept}>
              수락
            </button>
            <button className='modalButton' onClick={inviteDeny}>
              거절
            </button>
          </div>
        </div>
      )}
    </>
  );
}
export default InviteAcceptModal;